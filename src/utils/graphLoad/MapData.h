//
// Created by andremoreira9 on 5/8/21.
//

#ifndef FEUP_CAL_PROJ_MAPDATA_H
#define FEUP_CAL_PROJ_MAPDATA_H

#include <functional>
#include <utility>

enum NodeType {
    NORMAL,
    PARK
};

class NodeInfo {
public:

    NodeInfo():
            type (NodeType::NORMAL),
            maxCapacity(-1),
            currentCapacity(-1),
            priceFunction(nullptr){};

    NodeInfo(int maxCap, int currCap, std::function<double(int,int,int)> priceFunc):
        type (NodeType::PARK),
        maxCapacity(maxCap),
        currentCapacity(currCap),
        priceFunction(std::move(priceFunc)){};

    NodeType getType() const {
        return type;
    }

    void setType(NodeType type) {
        this->type = type;
    }

    int getMaxCapacity() const {
        return maxCapacity;
    }

    void setMaxCapacity(int maxCapacity) {
        this->maxCapacity = maxCapacity;
    }

    int getCurrentCapacity() const {
        return currentCapacity;
    }

    void setCurrentCapacity(int currentCapacity) {
        this->currentCapacity = currentCapacity;
    }

    double getPrice(int time) const {
        return priceFunction(time, currentCapacity, maxCapacity);
    }

    void setPriceFunction(const std::function<double(int, int, int)> &priceFunction) {
        NodeInfo::priceFunction = priceFunction;
    }

private:
    int maxCapacity;
    int currentCapacity;
    std::function<double(int,int,int)> priceFunction;
    NodeType type;
};

#endif //FEUP_CAL_PROJ_MAPDATA_H
