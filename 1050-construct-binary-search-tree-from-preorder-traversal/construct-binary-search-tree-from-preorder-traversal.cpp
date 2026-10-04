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
    TreeNode* buildBST(vector<int> &p, int &i, int ub) {
        if(i >= p.size()) return NULL;
        if(p[i] >= ub) return NULL;

        TreeNode* root = new TreeNode(p[i]);
        i++;
        root->left = buildBST(p, i, root->val);
        root->right = buildBST(p, i, ub);

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& p) {
        int n = p.size();
        if(n == 0) return NULL;
        int i = 0;

        return buildBST(p, i, INT_MAX);
    }
};