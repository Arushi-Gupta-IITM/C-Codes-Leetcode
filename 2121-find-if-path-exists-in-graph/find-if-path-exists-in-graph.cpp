class Solution {
public:
    void dfs(int u, vector<bool> &vis, vector<vector<int>> &adj, vector<int> &ans) {
        ans.push_back(u);
        vis[u] = true;

        for(int v : adj[u]) {
            if(vis[v] == false) dfs(v, vis, adj, ans);
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int src, int des) {
        // creating adjacency matrix
        vector<vector<int>> adj(n);

        for(int i=0; i<edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> vis(n, false);
        vector<int> ans;

        dfs(src, vis, adj, ans);

        for(int v : ans) {
            if(v == des) return true;
        }
        return false;
    }
};