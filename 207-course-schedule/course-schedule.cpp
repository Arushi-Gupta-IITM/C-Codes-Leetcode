class Solution {
public:
    bool isCycle(int u, vector<bool> &vis, vector<bool> &recPath, vector<vector<int>> &adj) {
        vis[u] = true;
        recPath[u] = true;

        for(int v : adj[u]) {
            if(vis[v] == false) {
                if(isCycle(v, vis, recPath, adj)) return true;
            } else if(recPath[v]) return true;
        }
        recPath[u] = false;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& edges) {
        // check for cycle in directed graph
        vector<vector<int>> adj(n);

        for(vector<int> e : edges) {
            adj[e[1]].push_back(e[0]);
        }

        // cycle in directed graph: using recursion Path
        vector<bool> vis(n, false);
        vector<bool> recPath(n, false);

        for(int i=0; i<n; i++) {
            if(vis[i] == false && isCycle(i, vis, recPath, adj)) return false; 
        }

        return true;
    }
};