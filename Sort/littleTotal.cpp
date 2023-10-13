// Author: Sardinary
// Date: 2023-08-11

#ifndef SORT_LITTLETOTAL_CPP_
#define SORT_LITTLETOTAL_CPP_

#include <iostream>
#include <vector>

using namespace std;

//求无序数组的小和
int merge(int* array, int l, int r, int m) {
    int temp[r - l + 1];
    int res = 0;
    int p = 0;
    int p1 = l;
    int p2 = m + 1;
    while (p1 <= m && p1 <= r) {
        res += array[p1] < array[p2] ? array[p1] * (r - p2 + 1) : 0;
        temp[p++] = array[p1] < array[p2] ? array[p1++] : array[p2++];
    }
    while (p1 <= m) {
        temp[p++] = array[p1++];
    }
    while (p2 <= r) {
        temp[p++] = array[p2++];
    }
    for (int i = 0; i < r - l + 1; i++) {
        array[l + i] = temp[i];
    }
    return res;
}

int process(int* array, int l, int r) {
    int m = l + ((r - l) >> 2);
    if (l == r) {
        return 0;
    }
    return process(array, l, m) + process(array, m + 1, r) + merge(array, l, r, m);
    
}
int littleTotal(int* array, int size) {
    return process(array, 0, size - 1);
}

int main() {
    int arr[5] = { 1,3,4,2,5 };
    cout << littleTotal(arr, 5) << endl;
}


#endif  // SORT_LITTLETOTAL_CPP_