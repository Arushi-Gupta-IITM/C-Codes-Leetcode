class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        // create adjacency list
        vector<vector<pair<int, int>>> adj(n);
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                int wt = abs(x1 - x2) + abs(y1 - y2);

                adj[i].push_back({j, wt});
                adj[j].push_back({i, wt});
            }
        }

        vector<bool> vis(n, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        // stores weight, vertex
        pq.push({0, 0});
        int minCost = 0;

        while(!pq.empty()) {
            int dist = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if(vis[u]) continue;

            minCost += dist;
            vis[u] = true;

            for(auto &p : adj[u]) {
                int v = p.first;
                int wt = p.second;
                pq.push({wt, v});
            }
        }

        return minCost;
    }
};