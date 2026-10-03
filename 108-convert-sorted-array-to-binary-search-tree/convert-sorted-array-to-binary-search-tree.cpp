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
    TreeNode* sortedArrayToBSTUtil(vector<int> &nums, int si, int ei) {
        if(si > ei) return NULL;

        int mid = si + (ei-si)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBSTUtil(nums, si, mid-1);
        root->right = sortedArrayToBSTUtil(nums, mid+1, ei);

        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return NULL;

        return sortedArrayToBSTUtil(nums, 0, n-1);
    }
};