// Author: Sardinary
// Date: 2023-10-07

#ifndef OJ_E_CPP_
#define OJ_E_CPP_

#define MAXSIZE 10
#include <iostream>

using namespace std;


class triple {
public:
    int i;
    int j;
    int value;
};

class Matrix {
public:
    int m;
    int n;
    int num;
    triple data[MAXSIZE];
};
Matrix* createM() {
    Matrix* matrix = new Matrix();
    cin >> matrix->m;
    cin >> matrix->n;
    int num;
    cin >> num;
    matrix->num = num;

    for (int i = 1; i <= num; i++) {
        cin >> matrix->data[i].i;
        cin >> matrix->data[i].j;
        cin >> matrix->data[i].value;
    }

    return matrix;
}

void show(Matrix* mt) {
    cout << mt->m << " ";
    cout << mt->n << " ";
    cout << mt->num << endl;;
    for (int i = 1; i <= mt->num; i++) {
        cout << mt->data[i].i << " ";
        cout << mt->data[i].j << " ";
        cout << mt->data[i].value << endl;
    }
    
}


// Matrix* transpose1(Matrix* m,Matrix* t) {
//     t->m = m->n;
//     t->n = m->m;
//     t->num = m->num;

//     if (t->num) {
//         triple* p = m->data;
//         p++;
//         cout << p->value;
//         int index = 1;
//         int i = 1;
//         while (i <= t->num) {
//             while (p != nullptr) {
//                 if (p->j == index) {
//                     t->data[i].i = p->j;
//                     t->data[i].j = p->i;
//                     t->data[i].value = p->value;
//                     i++;
//                 }
//                 p++;
//             }
//             index++;
//             p = m->data;
//             p++;
//         }
//     }

//     return t;
// }
void TransMatrix(Matrix* A, Matrix* B) {
    B->num = A->num;                 //复制A中非零元素个数至B
    B->m = A->n;                    //将A的行数与列数与B的交换
    B->n = A->m;
    int q = 1;                      //辅助计数器，记录转置后的三元组(下一个插入)元素下标值，
    //注意：这里A.data[]数组下标从1开始，三元组下标从0开始
    if (A) {
        for (int col = 0; col < A->n; col++) {      //按照列优先来遍历矩阵A(因为要先从列最小开始存放至新矩阵中)
            for (int p = 1; p <= A->num; p++) {      //按照下标递增次序遍历三元组，寻找列下标一致的
                if (col == (A->data[p].j)) {          //找到，则交换该三元组的行列下标放至新矩阵中
                    B->data[q].j = A->data[p].i;
                    B->data[q].i = A->data[p].j;
                    B->data[q].value = A->data[p].value;
                    q++;
                }
            }
        }
    }
}


int main() {
    Matrix* m = createM();
    Matrix* t = new Matrix();
    TransMatrix(m, t);
    show(t);
}





#endif  // OJ_E_CPP_