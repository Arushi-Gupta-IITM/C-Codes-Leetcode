/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    // use an unordered map to store original and cloned node
    unordered_map<Node*, Node*> mp;
    Node* cloneGraph(Node* node) {
        // base case
        if(node == nullptr) return nullptr;
        if(mp.find(node) != mp.end()) {
            return mp[node];
        }

        Node* copyNode = new Node(node->val);
        mp[node] = copyNode;

        vector<Node*> neigh = node->neighbors;
        vector<Node*> neighCopy;

        for(int i=0; i<neigh.size(); i++) {
            Node* u = neigh[i];
            neighCopy.push_back(cloneGraph(u));
        }
        copyNode->neighbors = neighCopy;        
        return copyNode;
    }
};