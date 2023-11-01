// Author: Sardinary
// Date: 2023-10-19

#ifndef OJ_QIUDAO_CPP_
#define OJ_QIUDAO_CPP_

#include <iostream>
#include <string>
using namespace std;

int arr[1000];

void fun(int size) {
    for (int i = 0; i < size; i++) {
        if ((i + 2) % 2 == 0) {
            arr[i] = arr[i] * arr[i + 1];
            arr[i + 1]--;
        }
    }

}

int main() {
    string exp;
    getline(cin, exp);

    int index1 = 0;
    int size = 0;
    for (int i = 0; i < exp.length(); i++) {
        if (exp[i] == ' ') {
            arr[size++] = atoi(exp.substr(index1, i - index1).c_str());
            index1 = i + 1;
        }
        if (i == exp.length() - 1) {
            arr[size++] = atoi(exp.substr(index1, i + 1 - index1).c_str());
        }
    }



    fun(size);

    

    if (arr[size - 1] < 0) {
        if (size == 2) {
            cout << "0 0";
            return 0;
        }

        for (int i = 0; i < size - 2; i++) {
            if (i == size - 3) {
                cout << arr[i];
            } else {
                cout << arr[i] << " ";
            }
        }
    } else {
        for (int i = 0; i < size; i++) {
            if (i == size - 1) {
                cout << arr[i];
            } else {
                cout << arr[i] << " ";
            }
        }
    }
    
}

#endif  // OJ_QIUDAO_CPP_