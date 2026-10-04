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
    TreeNode* prev = NULL;
    TreeNode* first = NULL;
    TreeNode* sec = NULL;
    
    void inorderTrav(TreeNode* root) {
        if(root == NULL) return;

        // left
        inorderTrav(root->left);
        // root
        if(prev != NULL && prev->val > root->val) {
            if(first == NULL) {
                first = prev;
            }
            sec = root;
        }
        prev = root;
        // right
        inorderTrav(root->right);
    }
    void recoverTree(TreeNode* root) {
       if(root == NULL) return;
       inorderTrav(root);

       int temp = first->val;
       first->val = sec->val;
       sec->val = temp; 
    }
};