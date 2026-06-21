class Solution {
public:

    int function(int i, int j, string& s1, string& s2, vector<vector<int>>&dp){
        if(i >= s1.length()){
            return (s2.length()-j);
        }
        if(j >= s2.length()){
            return (s1.length()-i);
        }
        if(dp[i][j] != -1) return dp[i][j];

        if(s1[i] == s2[j]){
            return dp[i][j] = function(i+1, j+1, s1, s2, dp);
        }

        return dp[i][j] =( 1 + min(min(function(i,j+1,s1,s2, dp), function(i+1,j,s1,s2, dp)),function(i+1,j+1,s1,s2, dp)));
        

    }

    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return function(0,0,word1,word2, dp);
    }
};