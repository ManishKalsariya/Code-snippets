// leetcode 44. Wildcard Matching
// solved using recursion + memoization
// for the '*' in the pattern, we have two choices:
// 1. we can ignore the '*' and move to the next character in the pattern
// 2. we can match the '*' with the current character in the string and move to the next character in both strings

class Solution {
public:

    bool helper(int i, int j, string &s, string &p, vector<vector<int>>& dp){


        if(i == s.length() && j == p.length())
            return true;


        if(j == p.length())
            return false;

  
        if(i == s.length()){
            while(j < p.length()){
                if(p[j] != '*')
                    return false;
                j++;
            }
            return true;
        }

        if(dp[i][j] != -1) return dp[i][j];

   
        if(s[i] == p[j] || p[j] == '?')
            return dp[i][j] = helper(i+1, j+1, s, p, dp);


        if(p[j] == '*'){
            return dp[i][j] = helper(i, j+1, s, p, dp) || 
                   helper(i+1, j, s, p, dp); 
        }

        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        vector<vector<int>>dp(max(s.length(), p.length()) + 1, vector<int>(max(s.length(), p.length()) + 1, -1));
        return helper(0,0,s,p, dp);
    }
};