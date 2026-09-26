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
    bool isUnivalUtil(TreeNode* root, int data) {
        if(root == NULL) return true;
        if(root->val != data) return false;

        return isUnivalUtil(root->left, data) && isUnivalUtil(root->right, data);
    }
    bool isUnivalTree(TreeNode* root) {
        if(root == NULL) return false;
        int data = root->val;

        return isUnivalUtil(root, data);
    }
};