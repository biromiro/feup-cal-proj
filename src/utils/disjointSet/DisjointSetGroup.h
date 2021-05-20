//
// Created by nunoa on 07/05/21.
//

#ifndef FEUP_CAL_PROJ_DISJOINTSETGROUP_H
#define FEUP_CAL_PROJ_DISJOINTSETGROUP_H


#include <vector>
#include "DisjointSet.h"

class DisjointSetGroup {
private:
    std::vector<DisjointSet*> values;
public:
    explicit DisjointSetGroup() {values = std::vector<DisjointSet*>();};
    ~DisjointSetGroup() {
        for(DisjointSet* value : values) {
            delete value;
        }
    }

    DisjointSet* createSet(int id);
    void linkSets(DisjointSet* first, DisjointSet* second);
    DisjointSet* findSet(int id);
    void reserveValues(size_t size);
};

#endif //FEUP_CAL_PROJ_DISJOINTSETGROUP_H
