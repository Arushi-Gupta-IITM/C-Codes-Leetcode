class Solution {
public:
    bool isCycle(int u, vector<vector<int>> &adj, vector<bool> &vis, vector<bool> &path) {
        vis[u] = true;
        path[u] = true;

        for(int v : adj[u]) {
            if(vis[v] == false && isCycle(v, adj, vis, path)) { 
                return true;
            } else if(path[v]) {
                return true;
            }
        }
        path[u] = false;
        return false;
    }
    bool canFinish(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V, vector<int>());
        // create adjacency list
        for(auto &e : edges) {
            int u = e[1];
            int v = e[0];

            adj[u].push_back(v);
        }
        // check if a cycle exists in a directed graph
        vector<bool> vis(V, false);
        vector<bool> path(V, false);
        for(int i=0; i<V; i++) {
            if(vis[i] == false && isCycle(i, adj, vis, path)) return false; 
        }

        // no cycle present, given graph is a DAG, top sort possible
        return true;
    }
};