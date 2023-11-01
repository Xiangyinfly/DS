#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    char data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(char val) : data(val), left(nullptr), right(nullptr) {}
};

TreeNode* buildTreeFromPrefixString(const string& prefixStr, int& index) {
    if (index >= prefixStr.length()) {
        return nullptr;
    }

    char currentChar = prefixStr[index++];
    if (currentChar == '#') {
        return nullptr;
    }

    TreeNode* newNode = new TreeNode(currentChar);
    newNode->left = buildTreeFromPrefixString(prefixStr, index);
    newNode->right = buildTreeFromPrefixString(prefixStr, index);

    return newNode;
}

void preorderTraversal(TreeNode* root) {
    if (root) {
        cout << root->data;
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void inorderTraversal(TreeNode* root) {
    if (root) {
        inorderTraversal(root->left);
        cout << root->data;
        inorderTraversal(root->right);
    }
}

void postorderTraversal(TreeNode* root) {
    if (root) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout << root->data;
    }
}

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

int maxDepth(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return max(leftDepth, rightDepth) + 1;
}

void iterativeInorderTraversal(TreeNode* root) {
    stack<TreeNode*> s;
    TreeNode* current = root;

    while (current != nullptr || !s.empty()) {
        while (current != nullptr) {
            s.push(current);
            current = current->left;
        }
        current = s.top();
        s.pop();
        cout << current->data;
        current = current->right;
    }
}

int main() {
    string prefixStr;
    cin >> prefixStr;
    int index = 0;

    TreeNode* root = buildTreeFromPrefixString(prefixStr, index);

    preorderTraversal(root);
    cout << endl;

    inorderTraversal(root);
    cout << endl;

    postorderTraversal(root);
    cout << endl;

    int leafCount = countLeaves(root);
    cout << leafCount << endl;

    int depth = maxDepth(root);
    cout << depth << endl;

    iterativeInorderTraversal(root);
    cout << endl;

    return 0;
}
