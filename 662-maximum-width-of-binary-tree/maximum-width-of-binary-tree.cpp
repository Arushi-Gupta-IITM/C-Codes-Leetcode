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
        if(root == NULL) return 0;

        // using complete binary tree index;
        queue<pair<TreeNode*, unsigned long long int>> q;
        q.push({root, 0});
        int ans = 0;

        while(q.size() > 0) {
            int currSize = q.size();
            int si = q.front().second;
            int ei = q.back().second;

            ans = max(ans, ei-si+1);

            // adding nodes of the next level
            for(int i=0; i<currSize; i++) {
                TreeNode* curr = q.front().first;
                unsigned long long int idx = q.front().second;
                q.pop();

                if(curr->left != NULL) q.push({curr->left, 2*idx+1});
                if(curr->right != NULL) q.push({curr->right, 2*idx+2});
            }
        }
        return ans;
    }
};