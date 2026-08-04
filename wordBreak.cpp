// Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

// Note that the same word in the dictionary may be reused multiple times in the segmentation.

 

// Example 1:

// Input: s = "leetcode", wordDict = ["leet","code"]
// Output: true
// Explanation: Return true because "leetcode" can be segmented as "leet code".
// Example 2:

// Input: s = "applepenapple", wordDict = ["apple","pen"]
// Output: true
// Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
// Note that you are allowed to reuse a dictionary word.
// Example 3:

// Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
// Output: false

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // Convert dictionary to a hash set for O(1) lookups
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        
        int n = s.length();
        // dp[i] will be true if s[0...i-1] can be segmented
        vector<bool> dp(n + 1, false);
        dp[0] = true; // Base case: empty prefix
        
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                // If s[0...j-1] is valid and s[j...i-1] is in wordDict
                if (dp[j] && wordSet.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break; // Move to the next index once dp[i] is true
                }
            }
        }
        
        return dp[n];
    }
};


//WORD BREAK PROBLEM USING PARTITION DP APPROACH

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
    int f(int i, int j, string& s, unordered_set<string>& wordSet, vector<vector<int>>& dp) {
        // Return cached result if already computed
        if (dp[i][j] != -1) return dp[i][j];

        // Extract current substring s[i...j]
        string sub = s.substr(i, j - i + 1);

        // Base Case: If the entire substring is directly present in the dictionary
        if (wordSet.count(sub)) return dp[i][j] = 1;

        // Partition Loop: Try splitting s[i...j] at every point k
        for (int k = i; k < j; k++) {
            bool left  = f(i, k, s, wordSet, dp);
            bool right = f(k + 1, j, s, wordSet, dp);

            // If both left and right sub-problems are valid, this partition works!
            if (left && right) {
                return dp[i][j] = 1;
            }
        }

        return dp[i][j] = 0;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        
        // dp[i][j] stores whether s[i...j] can be broken into valid words
        // -1: Unvisited, 0: False, 1: True
        vector<vector<int>> dp(n, vector<int>(n, -1));

        return f(0, n - 1, s, wordSet, dp) == 1;
    }
};