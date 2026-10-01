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
    TreeNode* buildTreeUtil(vector<int> &p, vector<int> &i, int &idx, int si, int ei, unordered_map<int, int> &mp) {
        if(si > ei) return NULL;
        if(idx >= p.size()) return NULL;

        TreeNode* root = new TreeNode(p[idx]); 
        int rootIdx = mp[p[idx]];
        idx++;
        
        root->left = buildTreeUtil(p, i, idx, si, rootIdx-1, mp);
        root->right = buildTreeUtil(p, i, idx, rootIdx+1, ei, mp);

        return root;
    }
    TreeNode* buildTree(vector<int>& p, vector<int>& i) {
        int n = p.size();
        if(n == 0) return NULL;

        // storing inorder sequence in a hashmap
        unordered_map<int, int> mp;
        for(int j=0; j<n; j++) {
            mp[i[j]] = j;
        }

        int idx = 0;
        return buildTreeUtil(p, i, idx, 0, n-1, mp);
    }
};