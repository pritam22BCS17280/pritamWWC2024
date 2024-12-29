/*
QUE.2:- preorder binary search tree.
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

// Recursive Preorder Traversal
void preorderTraversal(TreeNode* root) {
    if (root == NULL) return;

    // Visit the root node
    cout << root->val << " ";

    // Traverse the left subtree
    preorderTraversal(root->left);

    // Traverse the right subtree
    preorderTraversal(root->right);
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

    cout << "Preorder Traversal (Recursive): ";
    preorderTraversal(root);  // Output: 5 3 2 4 7 6 8

    return 0;
}
/*
OUTPUT

Preorder Traversal (Recursive): 5 3 2 4 7 6 8 
*/
