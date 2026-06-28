/*
=========================================
POWER OF 2 CHECK (Bit Manipulation)
=========================================

Condition:
    (n & (n - 1)) == 0

Meaning:
    n is a power of 2 (for n > 0)

Why?
    Power of 2 has exactly one set bit.

Examples:

    n = 8

    8     = 1000
    8 - 1 = 0111

    1000
  & 0111
    ----
    0000

    => Result = 0

Non-Power of 2:

    n = 12

    12     = 1100
    12 - 1 = 1011

    1100
  & 1011
    ----
    1000

    => Result != 0

Useful Applications:

1. Check if n is power of 2

    if (n > 0 && (n & (n - 1)) == 0)

2. CF 1475A / Odd Divisor

    Observation:
    - Every number = (power of 2) × (odd part)
    - Odd divisor > 1 exists iff n is NOT a power of 2

    if ((n & (n - 1)) == 0)
        cout << "NO";
    else
        cout << "YES";

Common Powers of 2:

    1, 2, 4, 8, 16, 32, 64, 128, ...

Time Complexity:
    O(1)

=========================================
*/

// leetcode 947 : https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/

//for adjacency list : 
            // for(int j = i + 1; j < n; j++) {
            //     if(stones[i][0] == stones[j][0] ||
            //        stones[i][1] == stones[j][1]) {

            //         adj[i].push_back(j);
            //         adj[j].push_back(i);
            //     }
            // }

            //it uses dfs to find the number of connected components in the graph, 
            // and then we can remove all the stones except one from each connected 
            // component, so the answer will be number of stones - number of connected components.


// for doing DP on any problem, we can use the following steps:
    // 1. express problem in terms of index
    // 2. do every required stuffs with index (like take, not take, etc.)
    // 3. return the answer ( like max, min, (take + not take), etc.)
    // 4. write base case for index

    // for memoization ( top-down DP):
    // 1. create a dp array of size (index + 1) and initialize it with -1
    // 2. check if dp[index] != -1, then return dp[index]
    // 3. store the answer in dp[index] before returning it

    // for tabulation ( bottom-up DP):
    // 1. create a dp array of size (index + 1) and initialize it with 0
    // 2. write the base case for index in dp array
    // 3. write a for loop from 1 to index and fill the dp array with the answer
    // 4. return dp[index]



    
    /*****************************************************************************************
                    CATALAN NUMBERS - COMPLETE REVISION NOTES (C++)

Definition:
-----------
The nth Catalan number represents the number of ways to divide/build certain
recursive structures.

Catalan Sequence:

n : 0   1   2   3   4   5    6
C : 1   1   2   5   14  42   132

------------------------------------------------------------------------------------------
MOST COMMON PROBLEMS
------------------------------------------------------------------------------------------

1. Number of valid parenthesis expressions of n pairs.
2. Number of Unique BSTs.
3. Number of Full Binary Trees.
4. Number of ways to triangulate a polygon.
5. Mountain-Valley problem.
6. Non-crossing handshakes.
7. GFG : Nth Catalan Number.
8. LeetCode 96 : Unique Binary Search Trees.

------------------------------------------------------------------------------------------
CORE IDEA
------------------------------------------------------------------------------------------

Suppose we choose one root / one pair / one split.

Left part has i elements.
Right part has n-i-1 elements.

Total ways:

    leftWays × rightWays

Considering all possible splits:

              n-1
Cn = Σ Ci × Cn-i-1
     i=0

Recurrence:

C0 = 1
C1 = 1

*****************************************************************************************/


/*****************************************************************************************
1. PURE RECURSION
Time : Exponential
Space: O(n)
*****************************************************************************************/

int catalan(int n)
{
    if (n <= 1)
        return 1;

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        ans += catalan(i) *
               catalan(n - i - 1);
    }

    return ans;
}


/*****************************************************************************************
2. MEMOIZATION
Time : O(n²)
Space: O(n)
*****************************************************************************************/

int solve(int n, vector<int>& dp)
{
    if (n <= 1)
        return 1;

    if (dp[n] != -1)
        return dp[n];

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        ans += solve(i, dp) *
               solve(n - i - 1, dp);
    }

    return dp[n] = ans;
}

int findCatalan(int n)
{
    vector<int> dp(n + 1, -1);

    return solve(n, dp);
}


/*****************************************************************************************
3. TABULATION
Time : O(n²)
Space: O(n)
*****************************************************************************************/

int findCatalan(int n)
{
    vector<long long> dp(n + 1);

    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = 0;

        for (int j = 0; j < i; j++)
        {
            dp[i] += dp[j] * dp[i - j - 1];
        }
    }

    return dp[n];
}


/*****************************************************************************************
PARENTHESES INTERPRETATION
------------------------------------------------------------------------------------------

For n pairs of parentheses:

n = 3

((()))
(()())
(())()
()(())
()()()

Answer = 5

Take first pair:

    ( LEFT ) RIGHT

LEFT uses i pairs.
RIGHT uses n-i-1 pairs.

Therefore:

Cn = C0Cn-1 + C1Cn-2 + ... + Cn-1C0

This gives the Catalan recurrence.

*****************************************************************************************/


/*****************************************************************************************
LEETCODE 96 : UNIQUE BINARY SEARCH TREES
------------------------------------------------------------------------------------------

Problem:
Given n nodes, count how many unique BSTs can be formed.

Example:

n = 3

Answer = 5

Reason:

Choose every node as root.

root = 1

Left subtree:
0 nodes

Right subtree:
2 nodes

Ways:

C0 × C2

--------------------------------

root = 2

Left:
1 node

Right:
1 node

Ways:

C1 × C1

--------------------------------

root = 3

Left:
2 nodes

Right:
0 nodes

Ways:

C2 × C0

Total:

C3 = C0C2 + C1C1 + C2C0 = 5

Therefore:

Unique BST problem = Catalan Number

*****************************************************************************************/


/*****************************************************************************************
LEETCODE 96 SOLUTION
*****************************************************************************************/

class Solution {
public:

    int solve(int n, vector<int>& dp)
    {
        if (n <= 1)
            return 1;

        if (dp[n] != -1)
            return dp[n];

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            ans += solve(i, dp) *
                   solve(n - i - 1, dp);
        }

        return dp[n] = ans;
    }

    int numTrees(int n)
    {
        vector<int> dp(n + 1, -1);

        return solve(n, dp);
    }
};


/*****************************************************************************************
MATHEMATICAL FORMULA
------------------------------------------------------------------------------------------

                (2n)!
Cn = ----------------------------
      (n+1)! × n!

or

            (2n C n)
Cn = ----------------
            n+1

Example:

C4

= 8! / (5! × 4!)

= 14

*****************************************************************************************/


/*****************************************************************************************
TIME COMPLEXITIES

Recursion      : Exponential

Memoization    : O(n²)

Tabulation     : O(n²)

Space          : O(n)

*****************************************************************************************/


/*****************************************************************************************
HOW TO RECOGNIZE CATALAN PROBLEMS?

Look for:

✓ Choose one root.
✓ Split into left and right.
✓ Answer = Left Ways × Right Ways.
✓ Sum over all possible choices.

Keywords:

• Unique BSTs
• Balanced Parentheses Count
• Full Binary Trees
• Polygon Triangulation
• Non-crossing Chords
• Mountain Valleys
• Handshakes

Whenever you see:

    Left possibilities × Right possibilities

for every split,

THINK:

        CATALAN NUMBER

*****************************************************************************************/


// # LeetCode 2527 - Find Xor-Beauty of Array

// ## Problem

// For every triplet `(i, j, k)`:

// ```cpp
// effective value = ((nums[i] | nums[j]) & nums[k])
// ```

// The xor-beauty of the array is the XOR of all such effective values.

// Return the xor-beauty.

// ---

// # Example

// ```cpp
// Input: nums = [1,4]

// Output: 5
// ```

// ---

// # First Observation

// The brute force solution would be:

// ```cpp
// for(i)
//     for(j)
//         for(k)
//             ans ^= ((nums[i] | nums[j]) & nums[k]);
// ```

// Time Complexity:

// ```text
// O(n³)
// ```

// Since:

// ```text
// n ≤ 100000
// ```

// This is impossible.

// ---

// # XOR Properties

// ## 1. Same numbers cancel

// ```text
// x ^ x = 0
// ```

// Example:

// ```text
// 5 ^ 5 = 0
// ```

// ---

// ## 2. XOR with 0

// ```text
// x ^ 0 = x
// ```

// ---

// ## 3. XOR is commutative

// ```text
// a ^ b = b ^ a
// ```

// ---

// # Main Intuition

// The expression is:

// ```text
// ((nums[i] | nums[j]) & nums[k])
// ```

// Consider two cases.

// ---

// ## Case 1 : i ≠ j

// Observe:

// ```text
// (nums[i] | nums[j])
// =
// (nums[j] | nums[i])
// ```

// Therefore:

// ```text
// ((nums[i] | nums[j]) & nums[k])

// and

// ((nums[j] | nums[i]) & nums[k])
// ```

// produce exactly the same value.

// Since both values appear in the final XOR:

// ```text
// x ^ x = 0
// ```

// they cancel each other.

// So all terms having:

// ```text
// i ≠ j
// ```

// disappear.

// ---

// ## Case 2 : i = j

// Then:

// ```text
// (nums[i] | nums[i])
// ```

// becomes:

// ```text
// nums[i]
// ```

// because:

// ```text
// x | x = x
// ```

// Thus:

// ```text
// ((nums[i] | nums[i]) & nums[k])

// = nums[i] & nums[k]
// ```

// ---

// Now consider:

// ```text
// i ≠ k
// ```

// Then:

// ```text
// nums[i] & nums[k]
// ```

// and

// ```text
// nums[k] & nums[i]
// ```

// are identical.

// Again:

// ```text
// x ^ x = 0
// ```

// Therefore these terms also cancel.

// ---

// Only one case survives:

// ```text
// i = j = k
// ```

// The effective value becomes:

// ```text
// (nums[i] | nums[i]) & nums[i]

// = nums[i] & nums[i]

// = nums[i]
// ```

// Thus only:

// ```text
// nums[0]
// nums[1]
// nums[2]
// ...
// nums[n-1]
// ```

// remain.

// Hence:

// ```text
// answer = nums[0] ^ nums[1] ^ nums[2] ^ ... ^ nums[n-1]
// ```

// ---

// # Final Formula

// ```cpp
// xorBeauty = XOR of all elements
// ```

// ---

// # Dry Run

// ```cpp
// nums = [1,4]
// ```

// Answer:

// ```text
// 1 ^ 4 = 5
// ```

// ---

// ```cpp
// nums = [15,45,20,2,34,35,5,44,32,30]
// ```

// Perform XOR of all numbers:

// ```text
// = 34
// ```

// ---

// # Algorithm

// 1. Initialize answer = 0.
// 2. Traverse the array.
// 3. XOR every number with answer.
// 4. Return answer.

// ---

// # Complexity Analysis

// ### Time Complexity

// ```text
// O(n)
// ```

// Only one traversal.

// ---

// ### Space Complexity

// ```text
// O(1)
// ```

// No extra space.

// ---

// # C++ Code

// ```cpp
// class Solution {
// public:
//     int xorBeauty(vector<int>& nums) {

//         int ans = 0;

//         // XOR every element
//         for (int num : nums) {
//             ans ^= num;
//         }

//         return ans;
//     }
// };
// ```

// ---

// # Important Bit Properties Used

// ```cpp
// x ^ x = 0
// x ^ 0 = x

// x | x = x
// x & x = x

// a | b = b | a
// a & b = b & a
// ```

// ---

// # Key Observation

// > Every term appears exactly twice and cancels out, except when:

// ```text
// i = j = k
// ```

// Therefore:

// ```cpp
// answer = XOR of all elements.
// ```

// ---

// # One-Line Solution

// ```cpp
// class Solution {
// public:
//     int xorBeauty(vector<int>& nums) {
//         int ans = 0;
//         for(int x : nums)
//             ans ^= x;
//         return ans;
//     }
// };
// ```
