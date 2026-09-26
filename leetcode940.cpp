// leetcode probem 940: Distinct Subsequences II
// in this, to solve we will have to use a recursive approach with memoization to count the distinct subsequences of a given string. The idea is to explore all possible subsequences by branching on the first occurrence of each character and keeping track of the counts using a memoization array to avoid redundant calculations. The final result will be returned modulo 1e9 + 7 to handle large numbers.

class Solution {
    int MOD = 1e9 + 7;
    vector<int> memo;

    int helper(int idx, const string& s) {
        if (idx >= s.length()) return 0;
        if (memo[idx] != -1) return memo[idx];

        long count = 0;
        vector<bool> visited(26, false);

        // Branch only on the FIRST occurrence of each character from 'idx' onward
        for (int i = idx; i < s.length(); i++) {
            int charIdx = s[i] - 'a';
            if (!visited[charIdx]) {
                visited[charIdx] = true;
                count = (count + 1 + helper(i + 1, s)) % MOD;
            }
        }

        return memo[idx] = count;
    }

public:
    int distinctSubseqII(string s) {
        int n = s.length();
        memo.assign(n, -1);
        return helper(0, s);
    }
};



// esiest method :
class Solution {
public:
    int distinctSubseqII(string s) {
        int MOD = 1e9 + 7;
        vector<long> ends(26, 0); // ends[i] = count of subsequences ending in ('a' + i)
        
        for (char c : s) {
            long totalSoFar = 0;
            for (long count : ends) {
                totalSoFar = (totalSoFar + count) % MOD;
            }
            // All existing subsequences + 1 (for single char "c")
            ends[c - 'a'] = (totalSoFar + 1) % MOD;
        }

        long result = 0;
        for (long count : ends) {
            result = (result + count) % MOD;
        }

        return result;
    }
};