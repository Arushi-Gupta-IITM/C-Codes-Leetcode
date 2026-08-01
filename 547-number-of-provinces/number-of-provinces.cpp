class Solution {
public:
    void dfs(int u, vector<bool> &vis, vector<vector<int>> &adj) {
        vis[u] = true;

        for(int v : adj[u]) {
            if(vis[v] == false) dfs(v, vis, adj);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(i != j && isConnected[i][j] == 1) {
                    adj[i].push_back(j);
                }
            }
        }

        int ans = 0;
        vector<bool> vis(n, false);

        for(int i=0; i<n; i++) {
            if(vis[i] == false) {
                ans++;
                dfs(i, vis, adj);
            }
        }

        return ans;
    }
};