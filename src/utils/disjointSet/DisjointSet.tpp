//
// Created by nunoa on 08/05/21.
//

template<class T>
SetType<T>* DisjointSet<T>::createSet(T value) {
    SetType<T>* set = new SetType<T>(value);

    values.push_back(set);
    return set;
}

template<class T>
SetType<T>* DisjointSet<T>::findSet(SetType<T>* set) {
    if(set != set->path) {
        set->path = findSet(set->path);
    }
    return set->path;
}

template<class T>
void DisjointSet<T>::linkSets(SetType<T> *first, SetType<T> *second) {
    if(first->rank > second->rank) {
        second->path = first;
    } else {
        first->path = second;
        if(first->rank == second->rank) second->rank++;
    }
}