#include "searching.h"
#include <iostream>
#include <math.h>
using namespace std;

template <class T>
int Searching<T>::binarySearch(T arr[], int left, int right, int x) {
    if(right >= left) {
        int middle = (right - left) / 2;
        int index = left + middle;
        cout << "We traverse on index: " << index << endl;
        if(x < arr[index]) {
            return binarySearch(arr, left, index - 1, x);
        }
        else if(x > arr[index]) {
            return binarySearch(arr, index + 1, right, x);   
        }
        else {
            return index;   
        }
    }
    return -1;
}

template <class T>
int Searching<T>::interpolationSearch(T arr[], int left, int right, int x) {
    if(right >= left && x >= arr[left]) {
        int index = left + (right - left) * (x - arr[left]) / (arr[right] - arr[left]);
        cout << "We traverse on index: " << index << endl;
        if(x < arr[index]) {
            return interpolationSearch(arr, left, index, x);
        }
        else if(x > arr[index]) {
            return interpolationSearch(arr, index + 1, right, x);
        }
        else return index;
    }
    return -1;
}

template <class T>
int Searching<T>::jumpSearch(T arr[], int x, int n) {
    int step = int(sqrt(n));
    int left = -1, right = -1;
    for(int i = 0; i < n && left == right; i += step) {
        cout << i << " ";
        if(x == arr[i]) {
            return i;
        }
        else if(x < arr[i]) {
            left = i - step;
            right = i;
        }
        else if(i < n && i + step >= n) {
            left = i;
            right = i + step;
        }
    }
    if(left != right) {
        for(int j = left + 1; j < right; j++) {
            cout << j << " ";
            if(x == arr[j]) {
                return j;
            }
        }
    }
    return -1;
}

template class Searching<int>;
template class Searching<float>;
template class Searching<double>;