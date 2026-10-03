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
    bool isValid(TreeNode* root, long long low, long long high) {
        if(root == NULL) return true;

        int curr = root->val;
        if(curr <= low || curr >= high) return false;

        return isValid(root->left, low, curr) && isValid(root->right, curr, high);
    }
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;

        long long low = LLONG_MIN;
        long long high = LLONG_MAX;

        return isValid(root, low, high);
    }
};