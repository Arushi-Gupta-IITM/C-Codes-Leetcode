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
    int ans = 0;

    int height(TreeNode* root) {
        if(root == NULL) return 0;
        int lh = height(root->left);
        int rh = height(root->right);

        int currDia = lh + rh;
        ans = max(ans, currDia);

        return max(lh, rh) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;

        height(root);

        return ans;
    }
};