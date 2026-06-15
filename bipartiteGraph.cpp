//Bipartite Graph bfs solution, it is basically telling 
// that if in the graph we can colour the graph with 2 colours
//  then it is a bipartite graph, if we find any adjacent vertices
// with same colour then it is not a bipartite graph.   

class Solution {
public:

    bool bfs(vector<vector<int>>& adj, vector<int>& colour, int src){
        queue<int>q;
        q.push(src);
        colour[src] = 1;

        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(auto v : adj[u]){
                if(colour[v] == -1){
                    colour[v] = !colour[u];
                    q.push(v);
                }else if(colour[v] == colour[u]){
                    return false;
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int>colour(n,-1);

        for(int i=0; i<n; i++){
            if(colour[i] == -1){
                if(!bfs(adj, colour, i)){
                    return false;
                }
            }
        }
        return true;
        
    }
};