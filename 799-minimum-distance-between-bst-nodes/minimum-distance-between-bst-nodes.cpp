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
    void inorderTrav(TreeNode* root, vector<int> &inorder) {
        if(root == NULL) return;

        inorderTrav(root->left, inorder);
        inorder.push_back(root->val);
        inorderTrav(root->right, inorder);
    }
    int minDiffInBST(TreeNode* root) {
        if(root == NULL) return 0;

        vector<int> inorder;
        inorderTrav(root, inorder);

        int ans = INT_MAX;
        int n = inorder.size();
        for(int i=0; i<n-1; i++) {
            ans = min(ans, inorder[i+1] - inorder[i]);
        }
        return ans;
    }
};