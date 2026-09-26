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
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        if(root->right == NULL && root->left == NULL) return 1;

        int leftDep = minDepth(root->left);
        int rightDep = minDepth(root->right);

        if(leftDep == 0) return 1 + rightDep;
        if(rightDep == 0) return 1 + leftDep;
        
        return 1 + min(leftDep, rightDep);
    }
};