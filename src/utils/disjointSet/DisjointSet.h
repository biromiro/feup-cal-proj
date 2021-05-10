//
// Created by nunoa on 07/05/21.
//

#ifndef FEUP_CAL_PROJ_DISJOINTSET_H
#define FEUP_CAL_PROJ_DISJOINTSET_H

class DisjointSetGroup;

class DisjointSet {
private:
    int id;
    DisjointSet* path;
    int rank;
public:
    DisjointSet(int _value) : id(_value) {
        path = this;
        rank = 0;
    }
    const int getId() const { return id; }
    const DisjointSet* getPath() const { return path; }
    int getRank() const { return rank; }

    friend class DisjointSetGroup;
};

#endif //FEUP_CAL_PROJ_DISJOINTSET_H
