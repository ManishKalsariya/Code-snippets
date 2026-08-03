class Solution {
  public:
    int helper(int idx, int w, vector<int>& price, vector<vector<int>>& dp) {
        // Base case: rod length 1 (idx 0) can fill capacity 'w' (w / 1) times
        if (idx == 0) {
            return w * price[0]; // equivalent to (w / 1) * price[0]
        }

        if (dp[idx][w] != -1) return dp[idx][w];

        // Choice 1: Don't cut a piece of length (idx + 1)
        int not_take = 0 + helper(idx - 1, w, price, dp);

        // Choice 2: Cut a piece of length (idx + 1) -> stay at idx for unlimited cuts
        int take = INT_MIN;
        int rod_len = idx + 1; // 0-based index corresponds to length (idx + 1)
        if (rod_len <= w) {
            take = price[idx] + helper(idx, w - rod_len, price, dp);
        }

        return dp[idx][w] = max(not_take, take);
    }

    int cutRod(vector<int>& price, int n) {
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return helper(n - 1, n, price, dp);
    }
};