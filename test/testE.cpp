// Author: Sardinary
// Date: 2023-11-18

#ifndef TEST_TESTE_CPP_
#define TEST_TESTE_CPP_

#include <iostream>
#include <string>
using namespace std;

class student {
public:
    string id;
    string name;
    int score;
};

//增
int cmp3(const void* a, const void* b) {
    return ((student*)a)->score > ((student*)b)->score;
}

int cmp1(const void* a, const void* b) {
    return ((student*)a)->id > ((student*)b)->id;
}

int cmp2(const void* a, const void* b) {
    return ((student*)a)->name < ((student*)b)->name;
}

int mode = 0;
int num = 0;
void excelSort() {
    cin >> num;
    cin >> mode;
    student students[num];

    for (int i = 0; i < num; i++) {
        cin >> students[i].id;
        cin >> students[i].name;
        cin >> students[i].score;
    }

    if (mode == 1) {
        qsort(students, num, sizeof(student), cmp1);

    }
    if (mode == 2) {
        qsort(students, num, sizeof(student), cmp2);
        qsort(students, num, sizeof(student), cmp1);
    }
    if (mode == 3) {
        qsort(students, num, sizeof(student), cmp3);
        qsort(students, num, sizeof(student), cmp1);
    }

    for (int i = 0; i < num; i++) {
        cout << students[i].id << " ";
        cout << students[i].name << " ";
        cout << students[i].score << " ";
        cout << endl;
    }

}

int main() {
    excelSort();
}


#endif  // TEST_TESTE_CPP_