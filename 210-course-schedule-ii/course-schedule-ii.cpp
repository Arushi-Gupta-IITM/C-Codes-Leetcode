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

    void dfs(int u, vector<bool> &vis, stack<int> &s, vector<vector<int>> &adj) {
        vis[u] = true;

        for(int v : adj[u]) {
            if(vis[v] == false) {
                dfs(v, vis, s, adj);
            }
        }
        s.push(u);
    }

    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        // adjacency list
        vector<vector<int>> adj(n);
        for(const auto &e : edges) {
            adj[e[1]].push_back(e[0]);
        }
        // check for cycle, if no cycle return topological sort
        bool cycle = false;
        vector<bool> vis(n, false);
        vector<bool> recPath(n, false);

        for(int i=0; i<n; i++) {
            if(vis[i] == false && isCycle(i, vis, recPath, adj)) cycle = true;
        }

        if(cycle) {
            vector<int> ans;
            return ans;
        }

        // no cycle exists topological sorting
        vis.assign(n, false);
        stack<int> s;

        for(int i=0; i<n; i++) {
            if(vis[i] == false) dfs(i, vis, s, adj);
        }

        vector<int> ans;
        while(!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }

        return ans;
    }
};