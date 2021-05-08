//
// Created by nunoa on 07/05/21.
//

#ifndef FEUP_CAL_PROJ_DISJOINTSET_H
#define FEUP_CAL_PROJ_DISJOINTSET_H


#include <vector>
#include "SetType.h"

class DisjointSet {
private:
    std::vector<SetType*> values;
public:
    DisjointSet() {values = std::vector<SetType*>();};
    ~DisjointSet() {
        for(SetType* value : values) {
            delete value;
        }
    }

    SetType* createSet(int id);
    void linkSets(SetType* first, SetType* second);
    SetType* findSet(int id);
};

#endif //FEUP_CAL_PROJ_DISJOINTSET_H
