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

    TreeNode* buildTreeUtil(vector<int>& preorder, vector<int>& inorder, int &idx, int si, int ei, unordered_map<int, int> &mp) {
        if(si > ei) return NULL;
        int rootIdx = mp[preorder[idx]];
        TreeNode* root = new TreeNode(preorder[idx]);
        idx++;

        root->left = buildTreeUtil(preorder, inorder, idx, si, rootIdx-1, mp);
        root->right = buildTreeUtil(preorder, inorder, idx, rootIdx+1, ei, mp);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // idx: works on preorder
        // si and ei work on inorder
        int si = 0, ei = inorder.size()-1;
        int idx = 0;

        unordered_map<int, int> mp; // stores inorder in a hashmap: data : index to find root index

        for(int i=0; i<inorder.size(); i++) {
            mp[inorder[i]] = i; // element : index
        }

        return buildTreeUtil(preorder, inorder, idx, si, ei, mp);
    }
};