class Solution {
public:
    void dfs(int u, vector<vector<int>> &adj, vector<bool> &vis) {
        vis[u] = true;

        for(int v : adj[u]) {
            if(vis[v] == false) dfs(v, adj, vis);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int ans = 0;
        
        // create adjacency list
        vector<vector<int>> adj(n);
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(i == j) continue;
                if(isConnected[i][j] == 1) {
                    adj[i].push_back(j);
                }
            }
        }

        vector<bool> vis(n, false);

        for(int i=0; i<n; i++) {
            if(vis[i] == false) {
                ans++;
                dfs(i, adj, vis);
            }
        }

        return ans;
    }
};