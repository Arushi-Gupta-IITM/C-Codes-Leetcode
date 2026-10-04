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
    TreeNode* insertNode(TreeNode* root, int el) {
        if(root == NULL) {
            TreeNode* newNode = new TreeNode(el);
            return newNode;
        }

        if(el < root->val) {
            root->left = insertNode(root->left, el);
        } else {
            root->right = insertNode(root->right, el);
        }
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& p) {
        int n = p.size();
        if(n == 0) return NULL;

        TreeNode* root = new TreeNode(p[0]);
        for(int i=1; i<n; i++) {
            insertNode(root, p[i]);
        }
        return root;
    }
};