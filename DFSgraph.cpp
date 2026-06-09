class Solution {
  public:
  
  void dfs(vector<vector<int>>& adj,int u, vector<int>&visited, vector<int>&ans){
      
      ans.push_back(u);
      visited[u] = 1;
      
      for(auto v : adj[u]){
          if(!visited[v]){
              dfs(adj,v,visited,ans);
          }
      }
      
  }
  
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        vector<int>visited(adj.size(), 0);
        vector<int>ans;
        dfs(adj,0,visited,ans);
        return ans;
    }
};