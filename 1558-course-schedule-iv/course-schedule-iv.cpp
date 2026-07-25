class Solution {
public:
    void topSort(int u, vector<vector<int>> &adj, vector<bool> &vis, stack<int> &s) {
        vis[u] = true;
        for(int v : adj[u]) {
            if(vis[v] == false) topSort(v, adj, vis, s);
        }
        s.push(u);
    }
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& edges, vector<vector<int>>& q) {
        // creating adjacency list
        vector<vector<int>> adj(n);
        for(int i=0; i<edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
        }

        // no cycle exists
        vector<bool> vis(n, false);
        stack<int> s;
        for(int i=0; i<n; i++) {
            if(vis[i] == false) topSort(i, adj, vis, s);
        }

        int pos = 0;
        unordered_map<int, int> mp;
        while(!s.empty()) {
            mp[s.top()] = pos;
            pos++;
            s.pop();
        }

        vector<bool> ans(q.size());
        for(int i=0; i<q.size(); i++) {
            int u = q[i][0];
            int v = q[i][1];

            if(mp[u] < mp[v]) ans[i] = true;
            else ans[i] = false;
        }

        return ans;
    }
};