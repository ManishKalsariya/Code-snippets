class Solution {
public:

    void dfs(int src, vector<vector<int>>&adj, vector<int>& visited){
        visited[src] = 1;

        for(auto v : adj[src]){
            if(!visited[v]){
                dfs(v,adj,visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
          
          int n = isConnected.size();
          vector<vector<int>>adj(n);
          vector<int> visited(n,0);

          for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(j != i && isConnected[i][j] == 1){
                    
                        adj[i].push_back(j);

                    }
                }
          }
            int cnt = 0;
          for(int i=0; i<n; i++){
            if(!visited[i]){
                cnt++;
                dfs(i, adj, visited);
            }
          }

          return cnt;

    }
};