// 0/1 knapsack problem on gfg : DP solution using memoization

class Solution {
  public:
    int helper(int idx, int w, vector<int>&val, vector<int>& wt, vector<vector<int>>& dp){
        if(idx == 0){
            if(wt[0] <= w){
                return val[0];
            }else{
                return 0;
            }
        }
        if(dp[idx][w] != -1) return dp[idx][w];
        
        int not_take = 0 + helper(idx-1, w, val, wt,dp);
        int take = INT_MIN;
        if(wt[idx] <= w){
            
            take = val[idx] + helper(idx-1, w-wt[idx], val, wt,dp);
            
        }
        return dp[idx][w] = max(not_take, take);
    }
    
  
    int knapsack(int w, vector<int> &val, vector<int> &wt) {
        // code here
        int idx = val.size()-1;
        vector<vector<int>> dp(val.size(), vector<int>(w + 1, -1));
        return helper(idx,w,val, wt, dp);
        
        
        
    }
};