//
// Created by nunoa on 07/05/21.
//

#ifndef FEUP_CAL_PROJ_SETTYPE_H
#define FEUP_CAL_PROJ_SETTYPE_H

class DisjointSet;

class SetType {
private:
    int id;
    SetType* path;
    int rank;
public:
    SetType(int _value) : id(_value) {
        path = this;
        rank = 0;
    }
    const int getId() const { return id; }
    const SetType* getPath() const { return path; }
    int getRank() const { return rank; }

    friend class DisjointSet;
};

#endif //FEUP_CAL_PROJ_SETTYPE_H
