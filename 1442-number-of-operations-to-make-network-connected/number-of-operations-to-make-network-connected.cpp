class Solution {
public:
    void dfs(int u, vector<bool> &vis, vector<vector<int>> &adj) {
        vis[u] = true;

        for(int v : adj[u]) {
            if(vis[v] == false) dfs(v, vis, adj);
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int con = connections.size();
        if(con < n-1) return -1; // not enough connections

        // creating adjacency matrix
        vector<vector<int>> adj(n);
        for(int i=0; i<connections.size(); i++) {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }

        // finding number of disconnected clusters
        vector<bool> vis(n, false);
        int ans = 0;
        for(int i=0; i<n; i++) {
            if(vis[i] == false) {
                ans++;
                dfs(i, vis, adj);
            }
        }
        return ans-1;
    }
};