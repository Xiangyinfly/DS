// Author: Sardinary
// Date: 2023-11-01

#ifndef CLAZZ_SECRCH_BST1_CPP_
#define CLAZZ_SECRCH_BST1_CPP_

#include <iostream>

using namespace std;

class BitNode {
public:
    int data;
    BitNode* lchild;
    BitNode* rchild;

    BitNode(int value) {
        this->data = value;
    }
    BitNode() {
    }

    BitNode(int value,BitNode* l,BitNode* r) {
        this->data = value;
        this->lchild = l;
        this->rchild = r;
    }
};


/**
 *f : 指向t的双亲
 *p : 如果查找成功，指向要查找的数据结点；如果查找失败，指向最后访问的结点
*/
bool searchBST(BitNode* t, int key, BitNode* f, BitNode* p) {
    if (!t) {
        p = f;
        return false;
    } else if (key == t->data) {
        p = t;
        return true;
    } else if (key > t->data) {
         return searchBST(t->rchild, key, t, p);
    } else {
        return searchBST(p->lchild, key, t, p);
    }
}

bool insertBTS(BitNode* tree, int value) {
    BitNode* p;
    BitNode* s;
    if (!searchBST(tree, value, nullptr, p)) {
        s = new BitNode(value, nullptr, nullptr);
        if (!p) {//如果是空指针
            tree = s;//插入s为新的根结点
        } else if (value < p->data) {
            p->lchild = s;
        } else {
            p->rchild == s;
        }

        return true;
    }
    return false;
}

bool deleteBTS(BitNode* t,int key) {
    if (!t) {
        return false;
    } else {
        if (key == t->data) {
            return del(t);
        } else if (key > t->data) {
            return deleteBTS(t->rchild, key);
        } else {
            return deleteBTS(t->lchild, key);
        }
    }
}

bool del(BitNode* t) {
    BitNode* p;
    BitNode* s;
    if (t->lchild == nullptr) {
        p = t;
        t = t->lchild;
        delete p;
    } else if (t->rchild == nullptr) {
        p = t;
        t = t->rchild;
        delete p;
    } else {
        p = t;
        s = t->lchild;
        while (s->rchild) {
            p = s;
            s = s->rchild;
        }

        t->data = s->data;
        if (t != p) {
            p->rchild = s->lchild;
        } else {
            p->lchild = s->lchild;
        }
        delete s;
    }

    return true;
}


#endif  // CLAZZ_SECRCH_BST1_CPP_