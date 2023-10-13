// Author: Sardinary
// Date: 2023-08-10

#ifndef TSET2_CPP_
#define TSET2_CPP_

#include <iostream>

using namespace std;

int partialMinNum(int* array, int size) {
    if (size == 1) {
        return 0;
    }
    if (array[0] < array[1]) {
        return 0;
    }
    if (array[size - 1] < array[size - 2]) {
        return size - 1;
    }

    int l = 0;
    int r = size - 1;
    while (l <= r) {
        int middle = l + ((r - l) >> 1);
        if (middle == 0) {
            return 1;
        }
        
        if (array[middle] < array[middle + 1] && array[middle] < array[middle - 1]) {
            return middle;
        } else if (array[middle] > array[middle - 1]) {
            r = middle - 1;
        } else {
            l = middle + 1;
        }
    }

    return -1;
}

int main() {
    int arr[] = { 2,0,3,4,5,6,7,8,9,10,11 };
}


#endif  // TSET2_CPP_