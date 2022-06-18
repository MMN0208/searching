#ifndef SEARCH_H
#define SEARCH_H

template <class T>
class Searching {
public: 
    int binarySearch(T array[], int left, int right, int x);
    int interpolationSearch(T array[], int left, int right, int x);
    int jumpSearch(T array[], int x, int n);
};

#endif