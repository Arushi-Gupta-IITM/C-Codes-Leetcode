/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isDescendant(TreeNode* root, TreeNode* desc) {
        if(root == NULL) return root == desc;

        if(root == desc) return true;

        return isDescendant(root->left, desc) || isDescendant(root->right, desc);      

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;

        if(isDescendant(p, q)) return p;
        if(isDescendant(q, p)) return q;

        if(isDescendant(root->right, p) && isDescendant(root->left, q)) return root;
        if(isDescendant(root->left, p) && isDescendant(root->right, q)) return root;

        if(isDescendant(root->left, p) && isDescendant(root->left, q)) return lowestCommonAncestor(root->left, p, q);

        if(isDescendant(root->right, p) && isDescendant(root->right, q)) return lowestCommonAncestor(root->right, p, q);

        return NULL;
    }
};