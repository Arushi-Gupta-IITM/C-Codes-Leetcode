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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        if(p == NULL && q == NULL) return NULL;

        if(p == NULL) return q;
        if(q == NULL) return p;

        int curr = root->val;
        int minVal = min(p->val, q->val);
        int maxVal = max(p->val, q->val);

        if(minVal <= curr && curr <= maxVal) return root;
        if(minVal < curr && maxVal < curr) return lowestCommonAncestor(root->left, p, q);
        else return lowestCommonAncestor(root->right, p, q);
    }
};