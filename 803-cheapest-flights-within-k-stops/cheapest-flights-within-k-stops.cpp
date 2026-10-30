class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // create an adjacency list
        vector<vector<pair<int, int>>> adj(n);
        for(auto &e : flights) {
            int u = e[0];
            int v = e[1];
            int cost = e[2];
            adj[u].push_back({v, cost});
        }

        queue<vector<int>> q; // vertex, cost, stops
        vector<int> totCost(n, INT_MAX);
        totCost[src] = 0;
        q.push({src, 0, -1});

        while(!q.empty()) {
            int u = q.front()[0];
            int cost = q.front()[1];
            int currStops = q.front()[2];
            q.pop();

            for(auto &neigh : adj[u]) {
                int v = neigh.first;
                int wt = neigh.second;
                if(totCost[u] != INT_MAX && totCost[v] > cost + wt && currStops+1 <= k) {
                    totCost[v] = cost + wt;
                    q.push({v, totCost[v], currStops+1});
                }
            }
        }
        if(totCost[dst] == INT_MAX) return -1;
        return totCost[dst];
    }
};