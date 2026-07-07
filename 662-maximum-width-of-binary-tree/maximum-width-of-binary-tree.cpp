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
    int widthOfBinaryTree(TreeNode* root) {
        // cbt index, left child = 2i+1, right child = 2i+2
        int maxWidth = 0;
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0}); // node, cbt index

        while(!q.empty()) {
            unsigned long long si = q.front().second;
            unsigned long long ei = q.back().second;
            int width = ei-si+1;
            int currLevel = q.size();
            maxWidth = max(maxWidth, width);

            for(int j=0; j<currLevel; j++) {
                TreeNode* curr = q.front().first;
                unsigned long long i = q.front().second;
                q.pop();

                if(curr->left != NULL) q.push({curr->left, 2*i+1});
                if(curr->right != NULL) q.push({curr->right, 2*i+2});
            }            
        }

        return maxWidth;
    }
};