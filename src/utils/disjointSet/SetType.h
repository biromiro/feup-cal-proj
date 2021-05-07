//
// Created by nunoa on 07/05/21.
//

#ifndef FEUP_CAL_PROJ_SETTYPE_H
#define FEUP_CAL_PROJ_SETTYPE_H


template <class T>
class SetType {
private:
    T value;
    SetType<T>* path;
    int rank;
public:
    SetType(T _value) : value(_value) {
        path = this;
        rank = 0;
    }
};

#endif //FEUP_CAL_PROJ_SETTYPE_H
