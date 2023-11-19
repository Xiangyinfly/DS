//
// Created by 陈文韬 on 2023/11/18.
//

// Author: Sardinary
// Date: 2023-11-18

#ifndef TEST_TESTD_CPP_
#define TEST_TESTD_CPP_

#include <iostream>
#include <string>
using namespace std;


class Node {
public:
    int data;
    Node* next;
};
class Element {
public:
    string data;
    Node* next;
};


Element elements[100];
int fileNum = 0;
int compareNum = 0;
double result[100];

void similarity() {
    cin >> fileNum;
    int count = 0;
    for (int i = 1; i <= fileNum; i++) {
        char c;
        bool key;
        string s;
        while ((c = getchar()) != '#') {
            if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) {
                key = true;
                if (c >= 65 && c <= 90) {
                    c = (char)(c + 32);
                }
                s += c;
            } else {
                if (s.length() < 3) {
                    key = false;
                }
                if (key) {
                    bool flag = true;
                    if (s.length() >= 10) {
                        s = s.substr(0, 10);
                    }
                    for (int j = 0; j < count; j++) {
                        if (s == elements[j].data) {
                            flag = false;
                            Node* p = elements[j].next;
                            while (p->next != nullptr) {
                                p = p->next;
                            }

                            Node* node = new Node();
                            node->data = i;
                            node->next = nullptr;

                            p->next = node;
                            break;
                        }
                    }
                    if (flag) {
                        elements[count].data = s;
                        Node* n = new Node();
                        n->data = i;
                        elements[count].next = n;
                        count++;
                    }
                }
                key = false;
                s = "";
            }
        }
        if (c == '#') {
            continue;
        }
    }


    cin >> compareNum;
    int fileA;
    int fileB;

    double countA = 0;
    double countB = 0;

    for (int j = 0; j < compareNum; j++) {
        cin >> fileA;
        cin >> fileB;

        for (int i = 0; i < count; i++) {
            Node* p = elements[i].next;

            bool foundA = false;
            bool foundB = false;

            while (p != nullptr) {
                if (p->data == fileA || p->data == fileB) {
                    if (p->data == fileA) {
                        foundA = true;
                    }
                    if (p->data == fileB) {
                        foundB = true;
                    }
                }
                p = p->next;
            }

            if (foundA || foundB) {
                countA++;
            }

            if (foundA && foundB) {
                countB++;
            }
        }


        result[j] = countB / countA;

        countA = 0;
        countB = 0;
    }

}

int main() {
    similarity();
    for (int i = 0; i < compareNum; ++i) {
        printf("%.1lf", result[i] * 100);
        cout << "%" << endl;
    }
}



#endif  // TEST_TESTD_CPP_