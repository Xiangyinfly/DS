// Author: Sardinary
// Date: 2023-08-10

#ifndef SORT_MERGESORT_CPP_
#define SORT_MERGESORT_CPP_

#include <iostream>

using namespace std;


void merge(int* array, int l, int r, int m) {
    int temp[r - l + 1];
    int i = 0;
    int p1 = l;
    int p2 = m + 1;

    while (p1 <= m && p2 <= r) {
        temp[i++] = array[p1] <= array[p2] ? array[p1++] : array[p2++];
    }
    while (p1 <= m) {
        temp[i++] = array[p1++];
    }
    while (p2 <= r) {
        temp[i++] = array[p2++];
    }

    for (int i = 0; i < r - l + 1; i++) {
        array[l + i] = temp[i];
    }
}


void process(int* array, int l, int r) {
    if (l == r) {
        return;
    }
    int mid = l + ((r - l) >> 2);
    process(array, l, mid);
    process(array, mid + 1, r);
    merge(array, l, r, mid);
}

void mergeSort(int* array, int size) {
    process(array, 0, size - 1);
}

int main() {
    int arr[] = { 1,3,2,4,2,3,166,34,23 };
    mergeSort(arr, 9);
    for (int i = 0; i < 9; i++) {
        cout << arr[i] << endl;
    }
}


#endif  // SORT_MERGESORT_CPP_