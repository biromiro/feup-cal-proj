//
// Created by nunoa on 07/05/21.
//

#ifndef FEUP_CAL_PROJ_DISJOINTSET_H
#define FEUP_CAL_PROJ_DISJOINTSET_H


#include <vector>
#include "SetType.h"

template <class T>
class DisjointSet {
private:
    std::vector<SetType<T>*> values;
public:
    DisjointSet() {values = std::vector<SetType<T>*>();};
    ~DisjointSet() {
        for(SetType<T>* value : values) {
            delete value;
        }
    }

    SetType<T>* createSet(T value);
    void linkSets(SetType<T>* first, SetType<T>* second);
    SetType<T>* findSet(SetType<T>* value);
};

#include "DisjointSet.tpp"

#endif //FEUP_CAL_PROJ_DISJOINTSET_H
