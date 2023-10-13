// Author: Sardinary
// Date: 2023-09-24

#ifndef OJ_TEST3_CPP_
#define OJ_TEST3_CPP_

#include <iostream>
#include <string>

using namespace std;

int judge(string s) {
    int n = s.length();
    
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - i - 1]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    string s;
    cin >> s;
    cout << judge(s) << endl;
}


#endif  // OJ_TEST3_CPP_