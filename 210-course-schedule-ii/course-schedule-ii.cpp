class Solution {
public:
    bool isCycleDFS(int u, vector<vector<int>> &adj, vector<bool> &vis, vector<bool> &path) {
        vis[u] = true;
        path[u] = true;

        for(int v : adj[u]) {
            if(vis[v] == false && isCycleDFS(v, adj, vis, path)) return true;
            else if(path[v]) return true;
        }
        path[u] = false;
        return false;
    }

    void topSort(int u, vector<vector<int>> &adj, vector<bool> &vis, stack<int> &s) {
        vis[u] = true;

        for(int v : adj[u]) {
            if(vis[v] == false) topSort(v, adj, vis, s);
        }
        s.push(u);
    }
    vector<int> findOrder(int V, vector<vector<int>>& edges) {        
        // create adjacency list
        vector<vector<int>> adj(V, vector<int>());
        for(auto &e : edges) {
            // u --> v
            int u = e[1];
            int v = e[0];
            adj[u].push_back(v);
        }
        // check for cycle
        bool isCycle = false;
        vector<bool> vis(V, false);
        vector<bool> path(V, false);
        for(int i=0; i<V; i++) {
            if(!vis[i] && isCycleDFS(i, adj, vis, path)) {
                isCycle = true;
                break;
            }
        }
        vector<int> ans;
        if(isCycle) return ans;

        // top sort
        fill(vis.begin(), vis.end(), false);
        stack<int> s;
        for(int i=0; i<V; i++) {
            if(vis[i] == false) topSort(i, adj, vis, s);
        }

        while(!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};