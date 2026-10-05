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
    TreeNode* buildTree(vector<int> &nums, int si, int ei) {
        if(si > ei) return NULL;

        int idx = -1;
        int maxVal = INT_MIN;
        for(int i=si; i<=ei; i++) {
            maxVal = max(maxVal, nums[i]);
            if(maxVal == nums[i]) idx = i;
        }

        TreeNode* root = new TreeNode(nums[idx]);
        root->left = buildTree(nums, si, idx-1);
        root->right = buildTree(nums, idx+1, ei);

        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return NULL;

        return buildTree(nums, 0, n-1);
    }
};