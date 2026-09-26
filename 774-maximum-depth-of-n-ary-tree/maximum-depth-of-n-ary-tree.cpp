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
    int maxDepth(Node* root) {
        if(root == NULL) return 0;
        
        vector<Node*> ch = root->children;
        int dep = 0;
        for(int i=0; i<ch.size(); i++) {
            dep = max(dep, maxDepth(ch[i]));
        }
        return 1 + dep;
    }
};