// Author: Sardinary
// Date: 2023-10-07

//F
#ifndef OJ_TEST6_CPP_
#define OJ_TEST6_CPP_

#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Node {
public:
    char data;
    Node* rchild;
    Node* lchild;
};

//AB#C##D##
Node* createTree(string& input, int& index) {
    if (index >= input.length()) {
        return nullptr;
    }

    char c = input[index];
    index++;

    if (c == '#') {
        return nullptr;
    }

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

void getLeafNum(Node* root,int& count) {
    if (root != nullptr) {
        if (root->lchild == nullptr && root->rchild == nullptr) {
            count++;
        }
        getLeafNum(root->lchild,count);
        getLeafNum(root->rchild,count);
    }
}

int getDepth(Node* node) {
    if (node == nullptr) {
        return 0;
    }

    int ldep = getDepth(node->lchild);
    int rdep = getDepth(node->rchild);

    int depth = (ldep >= rdep) ? (ldep + 1) : (rdep + 1);
    return depth;
}

void preOrder2(Node* root) {
    if (root == nullptr) {
        return;
    }

    stack<Node*> nodeStack;
    nodeStack.push(root);

    while (!nodeStack.empty()) {
        Node* current = nodeStack.top();
        nodeStack.pop();

        cout << current->data; // 输出当前节点的值

        // 先将右子节点入栈，再将左子节点入栈
        if (current->rchild != nullptr) {
            nodeStack.push(current->rchild);
        }
        if (current->lchild != nullptr) {
            nodeStack.push(current->lchild);
        }
    }
}


int main() {
    int leafCount = 0;
    int depth = 0;
    int index = 0;
    string s;
    cin >> s;
    Node* root = createTree(s,index);
    preOrder(root);
    cout << endl;
    inOrder(root);
    cout << endl;
    posOrder(root);
    cout << endl;
    getLeafNum(root, leafCount);
    cout << leafCount << endl;
    cout << getDepth(root) << endl;
    preOrder2(root);
}


#endif  // OJ_TEST6_CPP_