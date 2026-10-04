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
    TreeNode* findInorderSuccessor(TreeNode* root) {
        if(root == NULL) return NULL;

        while(root->left != NULL) {
            root = root->left;
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;

        if(key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if(key > root->val) {
            root->right = deleteNode(root->right, key);
        } else { // key == root
            // root has 0 children
            if(root->left == NULL && root->right == NULL) {
                delete root;
                return NULL;
            }
            // root has one child
            else if(root->left == NULL) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else if(root->right == NULL) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            } 
            // root has two children
            else { // is = left most node in the right subtree
                TreeNode* IS = findInorderSuccessor(root->right);
                root->val = IS->val;
                root->right = deleteNode(root->right, IS->val);
            }
        }
        return root;
    }
};