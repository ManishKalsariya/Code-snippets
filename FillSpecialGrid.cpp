//  Fill a Special Grid : 
// leetcode weekly contest 448;

class Solution {
public:
    void fillGrid(vector<vector<int>>& grid, int r_start, int r_end, int c_start, int c_end, int& cnt) {
        // Base case: If the subgrid is 1x1, fill it and return
        if (r_start == r_end && c_start == c_end) {
            grid[r_start][c_start] = cnt++;
            return;
        }

        int r_mid = r_start + (r_end - r_start) / 2;
        int c_mid = c_start + (c_end - c_start) / 2;

        // Recursively fill each quadrant in the order specified by the problem:
        // 1. Top-Right
        fillGrid(grid, r_start, r_mid, c_mid + 1, c_end, cnt);
        // 2. Bottom-Right
        fillGrid(grid, r_mid + 1, r_end, c_mid + 1, c_end, cnt);
        // 3. Bottom-Left
        fillGrid(grid, r_mid + 1, r_end, c_start, c_mid, cnt);
        // 4. Top-Left
        fillGrid(grid, r_start, r_mid, c_start, c_mid, cnt);
    }

    vector<vector<int>> specialGrid(int n) {
        int sz = 1 << n; // Equivalent to pow(2, n)
        vector<vector<int>> grid(sz, vector<int>(sz));
        int cnt = 0;
        
        fillGrid(grid, 0, sz - 1, 0, sz - 1, cnt);
        
        return grid;
    }
};