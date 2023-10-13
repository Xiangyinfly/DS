// Author: Sardinary
// Date: 2023-09-18

#ifndef OJ_TEST1_CPP_
#define OJ_TEST1_CPP_

#include <iostream>
#include <string>

using namespace std;

string binary = "";

void toBinary(int num) {
    if (num == 1) {
        binary += "1";
        return;
    }

    
    if (num % 2 == 1) {
        binary += "1";
    } else {
        binary += "0";
    }
    toBinary(num / 2);
}

string trans(int num, int system) {
    
}

int main() {
    toBinary(12);
    cout << binary << endl; 
}


#endif  // OJ_TEST1_CPP_