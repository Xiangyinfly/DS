// Author: Sardinary
// Date: 2023-09-16

#ifndef KMP_KMP_CPP_
#define KMP_KMP_CPP_

#include <iostream>
#include <string>
using namespace std;


int* getNextArray(string& s) {
    int* next = new int[s.length()];
    if (s.length() == 1) {
        next[0] = -1;
        return next;
    }

    next[0] = -1;
    next[1] = 0;
    int i = 2;
    int cn = 0;
    while (i < s.length()) {
        if (s[i - 1] == s[cn]) {
            next[i++] = ++cn;
        } else if (cn > 0) {
            cn = next[cn];
        } else {
            next[i++] = 0;
        }
    }

    return next;
}


int getIndexOf(string s1, string s2) {
    if (s1.empty() || s2.empty() || s1.length() < 1 || s1.length() < s2.length()) {
        return -1;
    }

    int i = 0;
    int j = 0;
    int* next = getNextArray(s2);

    while (i < s1.length() && j < s2.length()) {
        if (s1[i] == s2[j]) {
            i++;
            j++;
        } else if (j == 0) { //next[j]==-1
            i++;
        } else {
            j = next[j];
        }
    }

    return j == s2.length() ? i - j : -1;
}

int main() {
    
}


#endif  // KMP_KMP_CPP_