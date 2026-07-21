// Q2. Find Mirror Score of a String
// Solved
// Medium
// 4 pt.
// You are given a string s.

// We define the mirror of a letter in the English alphabet as its corresponding letter when the alphabet is reversed. For example, the mirror of 'a' is 'z', and the mirror of 'y' is 'b'.

// Initially, all characters in the string s are unmarked.

// You start with a score of 0, and you perform the following process on the string s:

// Iterate through the string from left to right.
// At each index i, find the closest unmarked index j such that j < i and s[j] is the mirror of s[i]. Then, mark both indices i and j, and add the value i - j to the total score.
// If no such index j exists for the index i, move on to the next index without making any changes.
// Return the total score at the end of the process.

 

// Example 1:

// Input: s = "aczzx"

// Output: 5

// Explanation:

// i = 0. There is no index j that satisfies the conditions, so we skip.
// i = 1. There is no index j that satisfies the conditions, so we skip.
// i = 2. The closest index j that satisfies the conditions is j = 0, so we mark both indices 0 and 2, and then add 2 - 0 = 2 to the score.
// i = 3. There is no index j that satisfies the conditions, so we skip.
// i = 4. The closest index j that satisfies the conditions is j = 1, so we mark both indices 1 and 4, and then add 4 - 1 = 3 to the score.
// Example 2:

// Input: s = "abcdef"

// Output: 0

// Explanation:

// For each index i, there is no index j that satisfies the conditions.

 

// Constraints:

// 1 <= s.length <= 10^5
// s consists only of lowercase English letters.


USE OF STACKS IN VECTOR 

CODE :
#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    long long calculateScore(string s) {
        long long score = 0;
        int n = s.length();
        
        // 26 stacks to store the indices of each character 'a' through 'z'
        vector<stack<int>> charIndices(26);

        for (int i = 0; i < n; i++) {
            char curr = s[i];
            char mirror = 'z' - curr + 'a';
            int mirrorIdx = mirror - 'a';

            // If we have an unmarked index available for the mirror character
            if (!charIndices[mirrorIdx].empty()) {
                int j = charIndices[mirrorIdx].top();
                charIndices[mirrorIdx].pop(); // Mark both j (by popping) and i (by not pushing)
                
                score += (i - j);
            } else {
                // No match available; push current index i for future mirror matches
                charIndices[curr - 'a'].push(i);
            }
        }

        return score;
    }
};