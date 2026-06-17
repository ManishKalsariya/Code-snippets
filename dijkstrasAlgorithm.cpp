// dijkstra's algorithm to find the shortest path from a source vertex to
//  all other vertices in a graph

class Solution {
  public:
  
    vector<int> helper(vector<vector<pair<int,int>>>&adj, int v, int src){
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> >pq;
        pq.push({0,src}); // dist, node
        vector<int>dist(v,INT_MAX);
        dist[src] = 0;
        
        
        while(!pq.empty()){
            int wt = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            for(auto e : adj[u]){
                int v = e.first;
                int w = e.second;
                
                if(dist[v] > dist[u] + w){
                    dist[v] = dist[u]+w;
                    pq.push({dist[v], v});
                }
                
            }
        }
        return dist;
    }
  
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int,int>>>adj(V);
        
        for(auto it : edges){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]}); //{v,wt}
        }
        
        return helper(adj,V,src);
        
        
        
        
    }
};