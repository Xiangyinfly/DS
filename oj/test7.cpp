// Author: Sardinary
// Date: 2023-10-07

//G
#ifndef OJ_TEST7_CPP_
#define OJ_TEST7_CPP_

#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    char data;
    Node* rchild;
    Node* lchild;
};

Node* createTree(string& input, int& index) {
    if (index >= input.length()) {
        return nullptr;
    }

    char c = input[index];
    index++;


    Node* node = new Node();
    node->data = c;
    node->lchild = createTree(input, index);
    node->rchild = createTree(input, index);

    return node;
}

void preOrder(Node* root) {
    if (root != nullptr) {
        if (root->data != '\0') {
            cout << root->data;
        }
        preOrder(root->lchild);
        preOrder(root->rchild);
    }
}
void inOrder(Node* root) {
    if (root != nullptr) {
        inOrder(root->lchild);
        if (root->data != '\0') {
            cout << root->data;
        }
        inOrder(root->rchild);
    }
}
void posOrder(Node* root) {
    if (root != nullptr) {
        posOrder(root->lchild);
        posOrder(root->rchild);
        if (root->data != '\0') {
            cout << root->data;
        }

    }
}

int main() {
    int index = 0;
    string s;
    cin >> s;
    Node* root = createTree(s, index);
    preOrder(root);
    cout << endl;
    inOrder(root);
    cout << endl;
    posOrder(root);
}

// - +ab / de
// a + b - d / e
// ab + de / -

#endif  // OJ_TEST7_CPP_