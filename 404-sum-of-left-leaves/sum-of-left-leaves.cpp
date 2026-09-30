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
    void sumUtil(TreeNode* root, int &ans, bool isLeft) {
        if(root == NULL) return;

        if(isLeft && root->left == NULL && root->right == NULL) ans += root->val;

        sumUtil(root->left, ans, true);
        sumUtil(root->right, ans, false);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL) return 0;
        
        int ans = 0;
        sumUtil(root, ans, false);

        return ans;       
    }
};