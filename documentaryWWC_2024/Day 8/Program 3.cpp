/*
que:3:- Symmetric Tree.
*/
Code: 

#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Helper function to check if two trees are mirrors of each other
bool isMirror(TreeNode* tree1, TreeNode* tree2) {
    if (tree1 == NULL && tree2 == NULL) {
        return true;  // Both are empty
    }
    if (tree1 == NULL || tree2 == NULL) {
        return false;  // One is empty and the other is not
    }
    // Check if current nodes are equal and the subtrees are mirrors of each other
    return (tree1->val == tree2->val) &&
           isMirror(tree1->left, tree2->right) &&
           isMirror(tree1->right, tree2->left);
}

// Main function to check if a tree is symmetric
bool isSymmetric(TreeNode* root) {
    if (root == NULL) {
        return true;  // An empty tree is symmetric
    }
    return isMirror(root->left, root->right);  // Check if left and right subtrees are mirrors
}

int main() {
    // Example: Creating a symmetric binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);
    
    if (isSymmetric(root)) {
        cout << "The tree is symmetric." << endl;
    } else {
        cout << "The tree is not symmetric." << endl;
    }

    return 0;
}
/*
OUTPUT

The tree is symmetric.

*/
