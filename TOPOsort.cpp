class Solution {
  public:
  
    void topo_is_modification_of_dfs(vector<vector<int>>& adj,int u, vector<int>&visited, stack<int>& st){
      
      visited[u] = 1;
      
      for(auto v : adj[u]){
          if(!visited[v]){
              topo_is_modification_of_dfs(adj,v,visited,st);
          }
      }
      st.push(u);
      
    }
  
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int>visited(V,0);
        vector<vector<int>>adj(V);
        stack<int>st;
        for(auto& it : edges){
            adj[it[0]].push_back(it[1]);
        }
        
        for(int i=0; i<V; i++){
            if(!visited[i]){
                
                topo_is_modification_of_dfs(adj,i,visited,st);
            }
            
        }
        vector<int>ans;
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
            
        }
        
        return ans;
        
        
    }
};