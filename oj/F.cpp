// Author: Sardinary
// Date: 2023-10-29

//错误的！！！

#ifndef OJ_F_CPP_
#define OJ_F_CPP_

#include <iostream>
#include <string>
#include <stack>
using namespace std;

class TreeNode {
public:
    TreeNode(char val) : value(val), left(nullptr), right(nullptr) {};
    char value;
    TreeNode* left;
    TreeNode* right;
};


TreeNode* buildTreeFromPrefixString(const string& prefixStr, int& index) {
    if (index >= prefixStr.length()) {
        return nullptr;
    }

    char currentChar = prefixStr[index++];
    if (currentChar == ' ') {
        return nullptr;
    }

    TreeNode* newNode = new TreeNode(currentChar);
    newNode->left = buildTreeFromPrefixString(prefixStr, index);
    newNode->right = buildTreeFromPrefixString(prefixStr, index);

    return newNode;
}

void priOrder(TreeNode* node) {
    if (node != nullptr) {
        cout << node->value << " ";
        priOrder(node->left);
        priOrder(node->right);
    }
}


void inOrder(TreeNode* node) {
    if (node != nullptr) {
        inOrder(node->left);
        cout << node->value << " ";
        inOrder(node->right);
    }
}

void postOrder(TreeNode* node) {
    if (node != nullptr) {
        postOrder(node->left);
        postOrder(node->right);
        cout << node->value << " ";
    }
}

void inOrderWithoutR(TreeNode* root) {
    TreeNode* p = root;
    stack<TreeNode*> s;
    while (p || !s.empty()) {
        while (p) {
            s.push(p);
            p = p->left;
        }
        if (!s.empty()) {
            p = s.top();
            s.pop();
            cout << p->value << " ";
            p = p->right;
        }
    }
}

int leafNum(TreeNode* node) {
    if (node == nullptr) {
        return 0;
    }
    if (node->left == nullptr && node->right == nullptr) {
        return 1;
    }
    return leafNum(node->left) + leafNum(node->right);
}

int depth(TreeNode* node) {
    if (node == nullptr) {
        return 0;
    }
    int m = depth(node->left);
    int n = depth(node->right);

    return m > n ? m + 1 : n + 1;
}


int main() {
    int index = 0;
    string s;
    cin >> s;
    TreeNode* root = buildTreeFromPrefixString(s, index);
    priOrder(root);
    cout << endl;
    inOrder(root);
    cout << endl;

    postOrder(root);
    cout << endl;

    cout << leafNum(root) << endl;
    cout << depth(root) << endl;
    inOrderWithoutR(root);
}


// void preOrderWithoutRecursion(TreeNode* root) {
//     TreeNode* p = root;
//     stack<TreeNode*> s;
//     while (p || !s.empty()) {
//         while (p) {
//             cout << p->value << endl;
//             s.push(p);
//             p = p->left;
//         }
//         if (!s.empty()) {
//             p = s.top();
//             s.pop();
//             p = p->right;
//         }
//     }
// }
#endif  // OJ_F_CPP_