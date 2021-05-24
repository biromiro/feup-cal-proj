//
// Created by nrtc on 20/05/2021.
//

#ifndef FEUP_CAL_PROJ_JOURNEYFINDER_H
#define FEUP_CAL_PROJ_JOURNEYFINDER_H


#include <graphLoad/GraphLoader.tpp>
#include <utils/algorithm/Connectivity.tpp>
#include <utility>
#include <set>
#include "parkFinalInfo.h"

class ParkFinalInfo;

class JourneyFinder {
public:
    JourneyFinder(const std::string& nodePath, const std::string& edgePath);
    void addPointOfInterest(size_t newPOI);
    bool generateJourney(size_t origin, size_t destiny, size_t time, int maxSearchForPark);
    void clearPointsOfInterest();
    Connectivity<NodeInfo> checkConnectiviy();

    NodeInfo updateParkCapacity(size_t i, int i1);

    void removePark(size_t i);

    size_t findNode(double d, double d1);

private:
    size_t calculate(Graph<NodeInfo>& graph, size_t origin, size_t destiny, size_t time, int maxSearchForPark);
    size_t selectPark(vector<Node<NodeInfo> *>& parks, size_t time);
    void journeyToJSON();
    GraphLoader<NodeInfo> loader;
    std::set<size_t> pointsOfInterest;
    std::vector<std::pair<std::vector<Node<NodeInfo>*>, std::vector<Node<NodeInfo>*> >> paths;
    std::vector<std::vector<ParkFinalInfo>> parks;
    float distanceCoeffient = 0.5;
    float costCoeffient = 0.5;
};


#endif //FEUP_CAL_PROJ_JOURNEYFINDER_H
