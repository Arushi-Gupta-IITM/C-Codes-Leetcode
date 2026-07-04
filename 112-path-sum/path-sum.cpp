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
    bool hasPathSum(TreeNode* root, int tar) {
        if(root == NULL) return false; // null node

        if(root->left == NULL && root->right == NULL) { // leaf node
            return tar == root->val;
        }

        return hasPathSum(root->left, tar - root->val) || hasPathSum(root->right, tar - root->val);
    }
};