// Author: Sardinary
// Date: 2023-09-20

#ifndef CLAZZ_TREE_TREE1_CPP_
#define CLAZZ_TREE_TREE1_CPP_

#include <iostream>

using namespace std;

class BitNode {
public:
    int value;
    BitNode* lchild;
    BitNode* rchild;
    //tag:1=线索化 0=孩子
    int ltag = 0;
    int rtag = 0;
};

BitNode* pre;


void preOrder(BitNode* b) {
    if (b == NULL) {
        return;
    }
    cout << b->value << endl;
    preOrder(b->lchild);
    preOrder(b->rchild);
}

void inThreading(BitNode* b) {
    if (b) {
        inThreading(b->lchild);
        if (!b->lchild) {
            b->ltag = 1;
            b->lchild = pre;
        }
        if (!pre->rchild) {
            pre->rtag = 1;
            pre->rchild = b;
        }
        pre = b;
        inThreading(b->rchild);
    }
}

void threadInOrder(BitNode* b) {
    BitNode* p;
    p->lchild = b;
    //如果有左孩子，就p = p->lchild；如果没有了就按线索遍历
    while (p != b) {
        while (p->ltag == 0) {//ltag == 0，即中序遍历的第一个节点
            p = p->lchild;
        }
        cout << p->value << endl;
        while (p->rtag == 1 && p->rchild != b) {
            p = p->rchild;
            cout << p->value << endl;
        }
        p = p->rchild;
    }
}



int main() {
    BitNode* treeRoot = new BitNode();
    BitNode* tree1 = new BitNode();
    BitNode* tree2 = new BitNode();
    BitNode* tree3 = new BitNode();
    treeRoot->value = 0;
    tree1->value = 1;
    tree2->value = 2;
    tree3->value = 3;

    treeRoot->lchild = tree1;
    treeRoot->rchild = tree2;
    tree1->lchild = tree3;

    preOrder(treeRoot);

    delete(treeRoot);
    delete(tree1);
    delete(tree2);
    delete(tree3);
}
    

#endif  // CLAZZ_TREE_TREE1_CPP_