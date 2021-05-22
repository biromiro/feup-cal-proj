//
// Created by nrtc on 20/05/2021.
//

#include <exception/noNodeWithID/noNodeWithID.h>
#include <algorithm/TravelingSalesman.h>
#include <algorithm/MinimumSpanningTrees.h>
#include <algorithm/Pathfinding.h>
#include <exception/noParkFound/noParkFound.h>
#include <exception/noFoundPath/noFoundPath.h>
#include "journeyFinder.h"

JourneyFinder::JourneyFinder(const string &nodePath, const string &edgePath) :
loader(GraphLoader<NodeInfo>(nodePath, edgePath, NodeMode::GRID)),
gv(GraphManager(600, 600, "")){}

void JourneyFinder::addPointOfInterest(size_t newPOI) {
    Graph<NodeInfo> graph = loader.getGraph();
    if(graph.findNode(newPOI) == nullptr) throw NoNodeWithID(newPOI, "There's no such POI node!");
    pointsOfInterest.push_back(newPOI);
}

bool JourneyFinder::generateJourney(size_t origin, size_t destiny, size_t time, int maxSearchForPark) {
    Graph<NodeInfo> graph = loader.getGraph();
    if(graph.findNode(origin) == nullptr) throw NoNodeWithID(origin, "There's no such origin node!");

    std::vector<Node<NodeInfo>*> vec;
    std::vector<int> orderedPOI;

    for(size_t val: pointsOfInterest){
        if(val == origin || val == destiny) continue;
        vec.push_back(graph.findNode(val));
    }

    Node<NodeInfo>* orig = graph.findNode(origin);
    Node<NodeInfo>* dest = graph.findNode(destiny);

    if(pointsOfInterest.size() < 8)
        orderedPOI = TravelingSalesman<NodeInfo>::bruteForce(vec, orig, dest);
    else
        orderedPOI = MinimumSpanningTrees<NodeInfo>::calculateTreeKruskal(vec, orig, dest);

    orderedPOI.push_back(destiny);

    size_t o = origin;
    for(int i = 0; i < orderedPOI.size(); i++){
        size_t d = orderedPOI.at(i);
        if(i == orderedPOI.size() - 1) o = calculate(graph, o, d, true, time, maxSearchForPark);
        else o = calculate(graph, o, d, false, time, maxSearchForPark);
    }

    return true;
}

size_t JourneyFinder::calculate(Graph<NodeInfo>& graph,
                                size_t origin, size_t destiny, bool final, size_t time, int maxSearchForPark) {

    vector<Node<NodeInfo> *> parks;
    Pathfinding::dijkstraAdaptation<NodeInfo>(graph, parks, destiny, maxSearchForPark);
    if(parks.empty())
        throw NoParkFound(destiny, "No parks were found.");

    vector<Edge<NodeInfo>*> pathToDest, pathToPark;
    size_t bestPark = selectPark(parks, time);
    int res = Pathfinding::getOrderedPath(graph, bestPark, destiny, pathToDest);
    if(!res)
        throw NoFoundPath("Couldn't get the ordered path from a park to the destiny!");

    gv.buildPath(pathToDest, GraphViewer::ORANGE);

    if(!Pathfinding::aStarAdaptation(graph, origin, bestPark))
        throw NoFoundPath("Couldn't get the ordered path from the origin to the park!");

    std::cout << Pathfinding::getOrderedPath(graph, origin, bestPark, pathToPark);
    gv.buildPath(pathToPark, GraphViewer::BLUE);

    paths.push_back(pathToPark);
    paths.push_back(pathToDest);
}

size_t JourneyFinder::selectPark(vector<Node<NodeInfo>*>& parks, size_t time) {
    size_t bestPark = 0;
    float bestRes = INF;
    for(Node<NodeInfo>* node: parks){
        float value = node->getInfo().getPrice(time) * costCoeffient + node->getDist() * distanceCoeffient;
        if(value < bestRes){
            bestRes = value;
            bestPark = node->getID();
        }
    }
    return bestPark;
}

void JourneyFinder::showJourney() {
    for(size_t i = 0; i < paths.size(); i += 2){
        gv.show();
        std::cout << "First path" << std::endl;
        gv.showPath(paths.at(i), TRAVEL);
        std::cout << "Second path" << std::endl;
        gv.showPath(paths.at(i+1), WALKING);
        gv.finish();
    }

}
