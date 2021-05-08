//
// Created by nunoa on 08/05/21.
//

#include "DisjointSet.h"

SetType* DisjointSet::createSet(int id) {
    SetType* set = new SetType(id);

    values.insert(values.begin() + id, set);
    return set;
}

SetType* DisjointSet::findSet(int id) {
    SetType* set = values.at(id);
    if(set != set->path) {
        set->path = findSet(set->path->getId());
    }
    return set->path;
}

void DisjointSet::linkSets(SetType *first, SetType *second) {
    if(first->rank > second->rank) {
        second->path = first;
    } else {
        first->path = second;
        if(first->rank == second->rank) second->rank++;
    }
}
