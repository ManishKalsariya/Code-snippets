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