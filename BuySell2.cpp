class Solution {
public:
    int profit = 0;
    int profitt(int idx, int buy, vector<int>&prices, vector<vector<int>>&dp){

        if(idx >= prices.size()){
            return 0;
        }

        if(dp[idx][buy] != -1) return dp[idx][buy];

        if(buy){
            profit = max((-prices[idx] + profitt(idx+1,0,prices,dp)) , (0 + profitt(idx+1, 1, prices, dp)));
        }
        else{
        
            profit = max((prices[idx] + profitt(idx+1,1,prices, dp)) , (0 + profitt(idx+1, 0, prices,dp)));

        }
        return dp[idx][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size()+1,vector<int>(2,-1));
        return profitt(0,1,prices, dp);
    }
};