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
    void treePaths(TreeNode* root, string &path, vector<string> &ans) {
        if(root == NULL) return;

        int data = root->val;
        string str = to_string(data);

        if(root->left == NULL && root->right == NULL) { // leaf node            
            path.append(str);
            ans.push_back(path);
            path.erase(path.size() - str.size());
            return;
        }

        str.append("->");
        path.append(str);

        treePaths(root->left, path, ans);
        treePaths(root->right, path, ans);

        path.erase(path.size() - str.size());
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(root == NULL) return ans;

        string path = "";
        treePaths(root, path, ans);
        return ans;
    }
};