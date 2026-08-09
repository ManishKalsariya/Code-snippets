// 695. Max Area of Island
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

// The area of an island is the number of cells with a value 1 in the island.

// Return the maximum area of an island in grid. If there is no island, return 0.

 

// Example 1:


// Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
// Output: 6
// Explanation: The answer is not 11, because the island must be connected 4-directionally.
// Example 2:

// Input: grid = [[0,0,0,0,0,0,0,0]]
// Output: 0
 

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 50
// grid[i][j] is either 0 or 1.

class Solution {
public:
    vector<int>r = {-1,0,1,0};
    vector<int>c = {0,1,0,-1};
    int bfs(int i, int j, vector<vector<int>>&grid, vector<vector<int>>&visited, int rows, int cols){
        queue<pair<int,int>>q;
        q.push({i,j});
        int cnt = 1;
        visited[i][j] = 1;

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;

            q.pop();
            for(int i=0; i<4; i++){
                int ur = row + r[i];
                int uc = col + c[i];

                if(ur>=0 && ur<rows && uc>=0 && uc<cols && !visited[ur][uc] && grid[ur][uc] == 1){
                    cnt++;
                    q.push({ur,uc});
                    visited[ur][uc] = 1;
                }
            }
        }

        return cnt;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int mxArea = 0;
        vector<vector<int>>visited(rows, vector<int>(cols,0));
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j] == 1 && !visited[i][j]){
                    int area = bfs(i,j,grid,visited,rows,cols);
                    mxArea = max(mxArea,area);
                }
            }
        }

        return mxArea;

    }
};