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
    int ans = INT_MIN;
    int maxPathSumUtil(TreeNode* root) {
        if(root == NULL) return 0;

        int leftSum = max(0, maxPathSumUtil(root->left));
        int rightSum = max(0, maxPathSumUtil(root->right));

        int curr = root->val + leftSum + rightSum;
        ans = max(ans, curr);

        return root->val + max(leftSum, rightSum);
    }
    int maxPathSum(TreeNode* root) {
        if(root == NULL) return 0;

        maxPathSumUtil(root);
        return ans;
    }
};