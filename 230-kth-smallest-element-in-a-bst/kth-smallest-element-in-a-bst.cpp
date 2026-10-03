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
    int kthSmallest(TreeNode* root, int k) {
        if(root == NULL) return -1;

        vector<int> inorder;
        inorderTrav(root, inorder);

        return inorder[k-1];
    }
};