// Author: Sardinary
// Date: 2023-08-09

#ifndef SORT_CPP_
#define SORT_CPP_

#include <iostream>

using namespace std;

void swap1(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
void swap(int& a, int& b) {
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

void bubbleSort(int* array, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                swap(array[j], array[j + 1]);
            }
        }
    }
}

void selectSort(int* array, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (array[i] > array[j]) {
                swap(array[i], array[j]);
            }
        }
    }
}

void insertSort(int* array, int size) {
    for (int i = 1; i < size; i++) {
        for (int j = i; j >= 1 && array[j] < array[j - 1]; j--) {
            swap(array[j], array[j - 1]);

        }
    }
}

int main() {
    int array[] = { 1,3,4,2,5,8,22 };
    //bubbleSort(array, 7);
    //selectSort(array, 7);
    insertSort(array, 7);
    for (int i = 0; i < 7; i++) {
        cout << array[i] << endl;
    }
}


#endif  // SORT_CPP_