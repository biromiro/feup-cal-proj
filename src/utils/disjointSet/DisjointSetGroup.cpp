//
// Created by nunoa on 08/05/21.
//

#include "DisjointSetGroup.h"

DisjointSet* DisjointSetGroup::createSet(int id) {
    DisjointSet* set = new DisjointSet(id);

    if(id >= values.size()) reserveValues(id+5);
    values.at(id) = set;
    return set;
}

DisjointSet* DisjointSetGroup::findSet(int id) {
    DisjointSet* set = values.at(id);
    if(set != set->path) {
        set->path = findSet(set->path->getId());
    }
    return set->path;
}

void DisjointSetGroup::linkSets(DisjointSet *first, DisjointSet *second) {
    if(first->rank > second->rank) {
        second->path = first;
    } else {
        first->path = second;
        if(first->rank == second->rank) second->rank++;
    }
}

void DisjointSetGroup::reserveValues(size_t size) {
    values.reserve(size);
    values.resize(size);
}
