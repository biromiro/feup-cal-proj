//
// Created by andremoreira9 on 5/8/21.
//

#ifndef FEUP_CAL_PROJ_MAPDATA_H
#define FEUP_CAL_PROJ_MAPDATA_H

#include <functional>

typedef double (*parkingPriceFunction)(int duration, int capacity, int currentCapacity);

typedef enum node_type {
    NORMAL,
    PARK
} node_type_t;

typedef struct node_info_t {
    int maxCapacity;
    int currentCapacity;
    std::function<double(int,int,int)> priceFunction;
};

typedef struct node_data_t {
    node_type_t nodeType;
    node_info_t nodeInfo;
};

#endif //FEUP_CAL_PROJ_MAPDATA_H
