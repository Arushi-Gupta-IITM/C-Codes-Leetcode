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
    unordered_map<Node*, Node*> mp; // stores the created nodes with original --> copy
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        if(mp.find(node) != mp.end()) return mp[node];        

        Node* copyNode = new Node(node->val);
        mp[node] = copyNode;

        vector<Node*> orgNeighbors = node->neighbors;
        vector<Node*> copyNeighbors;

        for(auto v : orgNeighbors) {
            if(mp.find(v) == mp.end()) { // copy of v has not been created in the memory
                Node* copyV = cloneGraph(v);
            }
            copyNeighbors.push_back(mp[v]);
        }

        copyNode->neighbors = copyNeighbors;
        return copyNode;
    }
};