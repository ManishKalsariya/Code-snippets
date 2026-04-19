class Solution {
public:
    // solution with both methods...recursion with memoiation :
    int solve(int ind, int canBuy, vector<int>&s,vector<vector<int>>&dp){
        int n = s.size();
        if(ind >= n) return 0;
        long profit = 0;

        if(dp[ind][canBuy] != -1) return dp[ind][canBuy];
        
        if(canBuy){
            profit =  max(-s[ind] + solve(ind+1,0,s,dp), 0 + solve(ind+1,1,s,dp));
        }else{
            profit = max(s[ind] + solve(ind+1,1,s,dp), 0 + solve(ind+1,0,s,dp)); 
        }
        return dp[ind][canBuy] = profit;
    }

    int maxProfit(vector<int>& s) {

        // tabulation method with space optimization.. :
        int n = s.size();
        vector<int> ahead(2,0), cur(2,0);
        ahead[0] = 0;
        ahead[1] = 0;

        for(int ind=n-1; ind>=0; ind--){
            for(int canBuy=1; canBuy>=0; canBuy--){
                long profit = 0;
                if(canBuy){
                    profit =  max(-s[ind] + ahead[0], 0 + ahead[1]);
                }else{
                    profit = max(s[ind] + ahead[1], 0 + ahead[0]); 
                }
                cur[canBuy] = profit;
               

            }
            ahead = cur;
        }

        return ahead[1];
        
    }
};