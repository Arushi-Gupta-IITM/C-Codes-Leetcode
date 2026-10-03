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
    void rangeSumBSTUtil(TreeNode* root, int low, int high, int &ans) {
        if(root == NULL) return;

        int curr = root->val;
        if(low <= curr && curr <= high) {
            ans += curr;
            rangeSumBSTUtil(root->left, low, high, ans);
            rangeSumBSTUtil(root->right, low, high, ans);
        } else if(curr < low) {
            rangeSumBSTUtil(root->right, low, high, ans);
        } else {
            rangeSumBSTUtil(root->left, low, high, ans);
        }
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        int ans = 0;
        rangeSumBSTUtil(root, low, high, ans);
        return ans;
    }
};