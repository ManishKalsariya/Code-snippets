class Solution {
  public:
  
    void bfs(vector<vector<int>> &adj, int u, vector<int>&visited, vector<int>&ans){
        queue<int>q;
        q.push(u);
        visited[u] = 1;
        
        while(!q.empty()){
            int u = q.front();
            q.pop();
            ans.push_back(u);
            for(auto v : adj[u]){
                if(!visited[v]){
                    visited[v] = 1;
                    q.push(v);
                    
                }
            }
            
        }

        
    }
  
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        vector<int>visited(adj.size(),0);
        vector<int>ans;
        bfs(adj,0,visited,ans);
        return ans;
        
    }
};