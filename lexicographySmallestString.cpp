// lexicographySmallestString.cpp

problem : 
You are given a string s of length n consisting of lowercase English letters.

You must perform exactly one operation by choosing any integer k such that 1 <= k <= n and either:

reverse the first k characters of s, or
reverse the last k characters of s.
Return the lexicographically smallest string that can be obtained after exactly one such operation.

 

Example 1:

Input: s = "dcab"

Output: "acdb"

Explanation:

Choose k = 3, reverse the first 3 characters.
Reverse "dca" to "acd", resulting string s = "acdb", which is the lexicographically smallest string achievable.

class Solution {
public:
    string lexSmallest(string s) {
        int n = s.length();
        string smallest = s;
        for(int k=1; k<=n; k++){
            string pre = s;
            string suf = s;
            reverse(pre.begin(), pre.begin()+k);
            smallest = min(smallest,pre);

            reverse(suf.end()-k, suf.end());
            smallest = min(smallest,suf);
        }
        return smallest;
    }
};