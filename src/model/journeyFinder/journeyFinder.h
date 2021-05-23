//
// Created by nrtc on 20/05/2021.
//

#ifndef FEUP_CAL_PROJ_JOURNEYFINDER_H
#define FEUP_CAL_PROJ_JOURNEYFINDER_H


#include <graphLoad/GraphLoader.tpp>
#include <graphLoad/GraphManager.h>
#include <utility>

class JourneyFinder {
public:
    JourneyFinder(const std::string& nodePath, const std::string& edgePath);
    void addPointOfInterest(size_t newPOI);
    bool generateJourney(size_t origin, size_t destiny, size_t time, int maxSearchForPark);
    void checkConnectiviy();
private:
    size_t calculate(Graph<NodeInfo>& graph, size_t origin, size_t destiny, size_t time, int maxSearchForPark);
    size_t selectPark(vector<Node<NodeInfo> *>& parks, size_t time);
    void journeyToJSON();

    GraphLoader<NodeInfo> loader;
    std::vector<size_t> pointsOfInterest;
    std::vector<std::pair<std::vector<Edge<NodeInfo>*>, std::vector<Edge<NodeInfo>*> >> paths;
    float distanceCoeffient = 0.5;
    float costCoeffient = 0.5;
};


#endif //FEUP_CAL_PROJ_JOURNEYFINDER_H
