// kosaraju's algorithm is used to find the number of strongly connected components (SCC) in a directed graph.
// it is a 2 pass algorithm, in first pass we do a dfs and push the nodes in a stack according to their
//  finishing time, in second pass we reverse the graph and do a dfs according to the finishing time of
//  the nodes in the stack, and count the number of times we do a dfs in second pass, that will be the number
//  of strongly connected components in the graph.


class Solution {
  public:
        
    void dfs(int src, vector<vector<int>>& adj, vector<int>& visited, stack<int>& st){
        visited[src] = 1;
        for(auto v : adj[src]){
            if(!visited[v]){
                dfs(v,adj,visited,st);
            }
        }
        st.push(src);
    }
    
    void dfsNew(int src, vector<vector<int>>& adj, vector<int>& visited){
        visited[src] = 1;
        for(auto v : adj[src]){
            if(!visited[v]){
                dfsNew(v,adj,visited);
            }
        }
 
    }
    
    int kosaraju(int v, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>>adj(v);
        
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
        }
    
        vector<int>visited(v,0);
        stack<int>st;
        
        for(int i=0; i<v; i++){
            if(!visited[i]){
                
                dfs(i,adj,visited,st);
            }
        }
        
        vector<vector<int>> adjT(v);
        
        for(auto it : edges){
            adjT[it[1]].push_back(it[0]);
        }
        
        vector<int>visitedT(v,0);
        int scc = 0;
        
        while(!st.empty()){
            int node = st.top();
            st.pop();
            if(!visitedT[node]){
                scc++;
                dfsNew(node, adjT, visitedT);
            }
        }
        return scc;
        
    }
};