// Author: Sardinary
// Date: 2023-10-19

#ifndef OJ_ERCHASHU_CPP_
#define OJ_ERCHASHU_CPP_

#include <iostream>
#include <string>
using namespace std;

// 二叉树结点的结构
struct TreeNode {
    char data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char val) : data(val), left(NULL), right(NULL) {}
};

// 通过先序和中序遍历序列还原二叉树
TreeNode* buildTree(string& preorder, string& inorder) {
    if (preorder.empty() || inorder.empty()) {
        return nullptr;
    }

    char rootValue = preorder[0];
    TreeNode* root = new TreeNode(rootValue);

    int rootIndex = inorder.find(rootValue);

    string leftInorder = inorder.substr(0, rootIndex);
    string rightInorder = inorder.substr(rootIndex + 1);

    string leftPreorder = preorder.substr(1, leftInorder.length());
    string rightPreorder = preorder.substr(1 + leftInorder.length());

    root->left = buildTree(leftPreorder, leftInorder);
    root->right = buildTree(rightPreorder, rightInorder);

    return root;
}

// 计算二叉树的深度
int calculateDepth(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }

    int leftDepth = calculateDepth(root->left);
    int rightDepth = calculateDepth(root->right);

    return 1 + max(leftDepth, rightDepth);
}

// 计算叶子节点的数量
int countLeaves(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }

    if (root->left == nullptr && root->right == nullptr) {
        return 1;
    }

    int leftLeaves = countLeaves(root->left);
    int rightLeaves = countLeaves(root->right);

    return leftLeaves + rightLeaves;
}

int main() {
    string preorder;
    string inorder;
    cin >> preorder;
    cin >> inorder;

    TreeNode* root = buildTree(preorder, inorder);

    int depth = calculateDepth(root);
    int leaves = countLeaves(root);

    cout << depth << endl;
    cout << leaves << endl;

    return 0;
}

#endif  // OJ_ERCHASHU_CPP_