/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void postorderUtil(Node* root, vector<int> &ans) {
        if(root == NULL) return;
        vector<Node*> ch = root->children;

        for(int i=0; i<ch.size(); i++) {
            postorderUtil(ch[i], ans);
        }
        ans.push_back(root->val);
    }
    vector<int> postorder(Node* root) {
        vector<int> ans;
        postorderUtil(root, ans);
        return ans;
    }
};