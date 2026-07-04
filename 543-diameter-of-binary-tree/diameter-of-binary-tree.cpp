/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int height(TreeNode* root) {
        if(root == NULL) return -1;

        return max(height(root->right), height(root->left)) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;

        // diameter does not pass through the root
        int d1 = diameterOfBinaryTree(root->left);
        int d2 = diameterOfBinaryTree(root->right);

        // diameter passes thoright root
        int d3 = 2 + height(root->left) + height(root->right);

        return max(d1, max(d2, d3));
    }
};