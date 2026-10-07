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
    TreeNode* flattenUtil(TreeNode* root) {
        if(root == NULL) return NULL;

        TreeNode* left = root->left;
        TreeNode* right = root->right;

        root->left = NULL;
        root->right = flattenUtil(left);

        TreeNode* temp = root;
        while(temp->right != NULL) temp = temp->right;

        temp->right = flattenUtil(right);
        return root;
    }

    void flatten(TreeNode* root) {
        if(root == NULL) return;
        flattenUtil(root);
    }
};