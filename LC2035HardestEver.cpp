// Leetcode 2035. Partition Array Into Two Arrays to Minimize Sum Difference
// this problem is a classic example of "meet in the middle" technique,
// where we split the array into two halves and generate all possible subset sums
// for each half. Then, we can use binary search to find the best combination of
// sums from both halves that minimizes the absolute difference between the two partitions.

//this problem is one of the most hardest problem i have ever seen...

class Solution {
public:
    int minimumDifference(vector<int>& nums) {

        int n = nums.size() / 2;

        vector<int> left(n), right(n);

        for (int i = 0; i < n; i++) {
            left[i] = nums[i];
            right[i] = nums[i + n];
        }

        vector<vector<int>> L(n + 1), R(n + 1);

        // Generate all subset sums using bitmasking
        for (int mask = 0; mask < (1 << n); mask++) {

            int cnt = 0;
            int sumL = 0;
            int sumR = 0;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    cnt++;
                    sumL += left[i];
                    sumR += right[i];
                }
            }

            L[cnt].push_back(sumL);
            R[cnt].push_back(sumR);
        }

        for (int i = 0; i <= n; i++)
            sort(R[i].begin(), R[i].end());

        int total = accumulate(nums.begin(), nums.end(), 0);

        int ans = INT_MAX;

        for (int k = 0; k <= n; k++) {

            for (int leftSum : L[k]) {

                int need = n - k;

                double target = (double)total / 2 - leftSum;

                auto &vec = R[need];

                auto it = lower_bound(vec.begin(), vec.end(), target);

                if (it != vec.end()) {
                    int chosen = leftSum + *it;
                    ans = min(ans, abs(total - 2 * chosen));
                }

                if (it != vec.begin()) {
                    --it;
                    int chosen = leftSum + *it;
                    ans = min(ans, abs(total - 2 * chosen));
                }
            }
        }

        return ans;
    }
};