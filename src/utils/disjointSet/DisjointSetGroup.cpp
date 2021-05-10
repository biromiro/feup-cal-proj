//
// Created by nunoa on 08/05/21.
//

#include "DisjointSetGroup.h"

DisjointSet* DisjointSetGroup::createSet(int id) {
    DisjointSet* set = new DisjointSet(id);

    values.insert(values.begin() + id, set);
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
