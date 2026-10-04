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
    TreeNode* buildBST(vector<int> &p, int si, int ei) {
        if(ei >= p.size()) return NULL;
        if(si > ei) return NULL;

        TreeNode* root = new TreeNode(p[si]);

        int idx = INT_MAX;
        for(int i=si+1; i<=ei; i++) {
            if(p[i] > p[si]) {
                idx = i;
                break;
            }
        }

        root->left = buildBST(p, si+1, min(idx-1, ei));
        root->right = buildBST(p, idx, ei);

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& p) {
        int n = p.size();
        if(n == 0) return NULL;

        return buildBST(p, 0, n-1);
    }
};