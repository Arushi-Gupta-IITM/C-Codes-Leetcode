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
    void binaryTreePathsUtil(TreeNode* root, string &path, vector<string> &ans) {
        if(root == NULL) {
            return;
        } 
               
        string curr = to_string(root->val);
        path.append(curr);
        path.append("->");

        if(root->left == NULL && root->right == NULL) {
            ans.push_back(path);
            path.erase(path.size()-(curr.size()+2));
            return;
        }
        binaryTreePathsUtil(root->left, path, ans);
        binaryTreePathsUtil(root->right, path, ans);

        path.erase(path.size()-(curr.size()+2));
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string path = "";

        binaryTreePathsUtil(root, path, ans);
        for(int i=0; i<ans.size(); i++) {
            string curr = ans[i];
            curr = curr.erase(curr.size()-2);
            ans[i] = curr;
        }
        return ans;
    }
};