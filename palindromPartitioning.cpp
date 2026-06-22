class Solution {
public:

    bool isPalindrome(string &s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right])
                return false;

            left++;
            right--;
        }
        return true;
    }

    void solve(int index,
               string &s,
               vector<string>& path,
               vector<vector<string>>& ans) {

        // Entire string is partitioned
        if (index == s.size()) {
            ans.push_back(path);
            return;
        }

        // Try every possible substring
        for (int i = index; i < s.size(); i++) {

            // Take only if palindrome
            if (isPalindrome(s, index, i)) {

                path.push_back(s.substr(index, i - index + 1));

                solve(i + 1, s, path, ans);

                // Backtrack
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {

        vector<vector<string>> ans;
        vector<string> path;

        solve(0, s, path, ans);

        return ans;
    }
};