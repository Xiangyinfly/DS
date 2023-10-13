// Author: Sardinary
// Date: 2023-08-09

#ifndef TEST1_CPP_
#define TEST1_CPP_

#include <iostream>

using namespace std;

void fun1(int* array,int size) {
    int eor = 0;
    for (int i = 0; i < size; i++) {
        eor ^= array[i];
    }
    int right = eor & (~eor + 1);
    int one = 0;
    for (int i = 0; i < size; i++) {
        if ((right & array[i]) == 0) { //&优先级低于==！
            one ^= array[i];
        }
    }
    cout << one << " " << (int)(one ^ eor) << endl;
}

int main() {
    int arr[] = { 1,1,1,3,3,5,5,2,4,4 };
    fun1(arr, 10);
}


#endif  // TEST1_CPP_