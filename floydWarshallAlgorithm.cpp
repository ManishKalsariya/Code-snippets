// floyd warshall algorithm is used to find the shortest distance 
// between all pairs of vertices in a weighted graph. It can handle 
// negative weights but not negative cycles. The algorithm works by 
// iteratively improving the estimate of the shortest path between any 
// two vertices, using each vertex as an intermediate point.

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>dist(n,vector<int>(n,1e9));
        int row = edges.size();
        int col = edges[0].size();

        for(auto it : edges){
            dist[it[0]][it[1]] = it[2];
            dist[it[1]][it[0]] = it[2];
        }
        for(int i=0; i<n; i++){
            dist[i][i] = 0;
        }

        for(int via = 0; via<n; via++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
                }
            }
        }
    int cnt = 1e9;
    int node = -1;
        for(int i=0; i<n; i++){
            int temp = 0;
            for(int j=0; j<n; j++){
                if(dist[i][j] <= distanceThreshold && j != i){
                    temp++;
                }
            }
            if(temp < cnt || (temp == cnt && i > node)){
                cnt = temp;
                node = i;
            }
            
        }
        return node;

    }
};