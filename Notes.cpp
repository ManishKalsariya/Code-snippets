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