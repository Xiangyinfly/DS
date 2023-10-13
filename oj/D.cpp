// Author: Sardinary
// Date: 2023-10-07

#ifndef OJ_D_CPP_
#define OJ_D_CPP_

#include <iostream>
#include <string>
using namespace std;

int num;
string* input;
string s;

void getInput() {
    
    cin >> num;
    input = new string[num];
    for (int i = 0; i < num; i++) {
        cin >> input[i];
    }

    cin >> s;
}

void match(string s) {
    double percent = 0;
    int maxMatchNum = 0;
    int matchIndex = 0;
    int sMaxMatchNum = 0;

    for (int i = 0; i < num; i++) {
        int index = 0;
        int j = 0;
        while (j < s.length() && j + index < input[i].length()) {
            if (input[i][j + index] == s[j]) {
                j++;
            } else {
                index++;
                j = 0;
            }

            if (j > sMaxMatchNum) {
                sMaxMatchNum = j;
                percent = sMaxMatchNum / (s.length() * 1.0);
                maxMatchNum = index + 1;
                matchIndex = i + 1;
            }
        }
    }

    cout << matchIndex << " ";
    cout << maxMatchNum << " ";
    printf("%.2lf%%", percent * 100);
}

int main() {
    getInput();
    match(s);
    delete[] input;
}


#endif  // OJ_D_CPP_