// leetcode 1976. Number of Ways to Arrive at Destination
// this problem can be solved using Dijkstra's algorithm to find the shortest
//  path from the source node to the destination node. We can also keep track
// of the number of ways to reach each node while finding the shortest path.

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int mod = 1e9 + 7;
        vector<vector<pair<int, int>>>adj(n);
        for(auto it : roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>>pq;
        pq.push({0,0});
        vector<int>ways(n,0);
        vector<long long>dist(n,LLONG_MAX);
        dist[0] = 0;
        ways[0] = 1;

        while(!pq.empty()){
            int u = pq.top().second;
            long long d = pq.top().first;
            pq.pop();
            if(d > dist[u]) continue;
            for(auto it : adj[u]){
                int v = it.first;
                long long wt = it.second;

                if(dist[v] > dist[u] + wt){
                    dist[v] = dist[u] + wt;
                    ways[v] = ways[u];
                    pq.push({dist[u]+wt, v});
                }else if(dist[v] != 1e9 && dist[v] == dist[u] + wt){
                    ways[v] = (ways[u] + ways[v])%mod;
                }
            }

        }
        return ways[n-1];

    }
};
