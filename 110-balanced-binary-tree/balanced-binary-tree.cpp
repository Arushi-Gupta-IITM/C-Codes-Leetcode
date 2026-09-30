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
    bool ans = true;
    int height(TreeNode* root) {
        if(root == NULL) return 0;

        int leftHt = height(root->left);
        int rightHt = height(root->right);

        if(abs(leftHt - rightHt) > 1) ans = false;

        return 1 + max(leftHt, rightHt);
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;

        ans = true;
        height(root);
        return ans;
    }
};