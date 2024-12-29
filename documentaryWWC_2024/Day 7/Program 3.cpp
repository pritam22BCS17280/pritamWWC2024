/*
QUE.3: Postorder Binary search tree on (LEET CODE).
  */


CODE :

#include <iostream>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Recursive Postorder Traversal
void postorderTraversal(TreeNode* root) {
    if (root == NULL) return;

    // Traverse the left subtree
    postorderTraversal(root->left);

    // Traverse the right subtree
    postorderTraversal(root->right);

    // Visit the root node
    cout << root->val << " ";
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

    cout << "Postorder Traversal (Recursive): ";
    postorderTraversal(root);  // Output: 2 4 3 6 8 7 5

    return 0;
}
/*
OUTPUT

Postorder Traversal (Recursive): 2 4 3 6 8 7 5 

*/
