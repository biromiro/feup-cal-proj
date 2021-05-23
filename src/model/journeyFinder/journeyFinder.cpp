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
loader(GraphLoader<NodeInfo>(nodePath, edgePath, NodeMode::COORDS)) {}

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
        o = calculate(graph, o, d, time, maxSearchForPark);
    }

    journeyToJSON();
    return true;
}

size_t JourneyFinder::calculate(Graph<NodeInfo>& graph,
                                size_t origin, size_t destiny, size_t time, int maxSearchForPark) {

    vector<Node<NodeInfo> *> parks;
    Pathfinding::dijkstraAdaptation<NodeInfo>(graph, parks, destiny, maxSearchForPark);
    if(parks.empty())
        throw NoParkFound(destiny, "No parks were found.");

    vector<Node<NodeInfo>*> pathToDest, pathToPark;
    size_t bestPark = selectPark(parks, time);

    Pathfinding::getOrderedPath(graph, destiny, bestPark, pathToDest);

    std::reverse(pathToDest.begin(), pathToDest.end());

    if(!Pathfinding::dijkstraAdaptation(graph, origin, bestPark))
        throw NoFoundPath("Couldn't get the ordered path from the origin to the park!");

    Pathfinding::getOrderedPath(graph, origin, bestPark, pathToPark);

    std::pair<std::vector<Node<NodeInfo>*>, vector<Node<NodeInfo>*>> pair(pathToPark, pathToDest);

    paths.push_back(pair);

    return bestPark;
}

size_t JourneyFinder::selectPark(vector<Node<NodeInfo>*>& parks, size_t time) {
    size_t bestPark = 0;
    float bestRes = INF;
    this->parks.push_back(std::vector<ParkFinalInfo>());
    for(Node<NodeInfo>* node: parks){
        float value = node->getInfo().getPrice(time) * costCoeffient + node->getDist() * distanceCoeffient;
        ParkFinalInfo parkFinalInfo(node->getDist(), value, node->getPos().getX(), node->getPos().getY());
        this->parks.at(this->parks.size()-1).push_back(parkFinalInfo);

        if(value < bestRes){
            bestRes = value;
            bestPark = node->getID();
        }
    }
    return bestPark;
}

void JourneyFinder::journeyToJSON() {
    std::ofstream journey("view/resources/journey.json");

    journey << "{\n  \"paths\": [\n";
    for(size_t j = 0; j < paths.size(); j++){
        journey << "    {\n";
        vector<Node<NodeInfo>*> pathToPark = paths.at(j).first;
        vector<Node<NodeInfo>*> pathToDest = paths.at(j).second;
        Node<NodeInfo>
                *originNode = pathToPark.at(0),
                *parkNode = pathToPark.at(pathToPark.size() - 1),
                *destNode = pathToDest.at(pathToDest.size() - 1);

        journey << "      \"park\": ["
        << parkNode->getPos().getY()
        << ","
        << parkNode->getPos().getX()
        << "],\n";

        journey << "      \"orig\": ["
        << originNode->getPos().getY()
        << ","
        << originNode->getPos().getX()
        << "],\n";

        journey << "      \"dest\": ["
        << destNode->getPos().getY()
        << ","
        << destNode->getPos().getX()
        << "],\n";

        journey << "      \"parks\": [\n";
        for(size_t i = 0; i < parks.at(j).size(); i++){
            parks.at(j).at(i).toJson(journey);
            if(i == parks.at(j).size() - 1) journey << "\n";
            else journey << ",\n";
        }
        journey << "      ],\n";

        journey << "      \"origToPark\": [\n";
        for(size_t i = 1; i < pathToPark.size() - 1; i++){
            Node<NodeInfo>* curNode = pathToPark.at(i);
            journey << "         ["
                    << curNode->getPos().getY()
                    << "," << curNode->getPos().getX()
                    << "]";

            if(i == pathToPark.size() - 2) journey << "\n";
            else journey << ",\n";
        }
        journey << "      ],\n";

        journey << "      \"parkToDest\": [\n";
        for(size_t i = 1; i < pathToDest.size() - 1; i++){
            Node<NodeInfo>* curNode = pathToDest.at(i);
            journey << "         ["
                    << curNode->getPos().getY()
                    << "," << curNode->getPos().getX()
                    << "]";

            if(i == pathToDest.size() - 2) journey << "\n";
            else journey << ",\n";
        }
        journey << "      ]\n";

        if(j == paths.size() - 1) journey << "    }\n";
        else journey << "    },\n";
    }
    journey << "   ]\n}";

}

void JourneyFinder::checkConnectiviy() {

}
