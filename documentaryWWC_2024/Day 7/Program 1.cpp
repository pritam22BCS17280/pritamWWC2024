/*
QUE.1 inorder Binary search tree on (leet code )
*/
CODE:

#include <iostream>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Recursive Inorder Traversal
void inorderTraversal(TreeNode* root) {
    if (root == NULL) return;

    // Traverse the left subtree
    inorderTraversal(root->left);

    // Visit the root node
    cout << root->val << " ";

    // Traverse the right subtree
    inorderTraversal(root->right);
}

int main() {
    // Example Tree:
    //        5
    //       / \
    //      3   7
    //     / \   / \
    //    2   4 6   8

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);

    cout << "Inorder Traversal (Recursive): ";
    inorderTraversal(root);  // Output: 2 3 4 5 6 7 8

    return 0;
}
/*
OUTPUT

Inorder Traversal (Recursive): 2 3 4 5 6 7 8
*/
