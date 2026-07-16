// problem : Minimum Swaps to Sort by Digit Sum

// Given an array of integers, we need to find
// the minimum number of swaps required to sort
// the array based on the sum of digits of each integer.
// If two integers have the same digit sum, they should be
// sorted in ascending order.

class Solution {
public:
    long long sum(int num) { // Optimized: Calculate sum using math instead of converting to string
        long long sm = 0;
        while (num > 0) {
            sm += num % 10;
            num /= 10;
        }
        return sm;
    }
    
    int minSwaps(vector<int>& nums) {
        int len = nums.size();
        
        // vc will store: {digit_sum, {original_num, original_index}}
        vector<pair<long long, pair<int, int>>> vc;
        for(int i = 0; i < len; i++) {
            long long sm = sum(nums[i]);
            vc.push_back({sm, {nums[i], i}});
        }

        // Sort based on custom rules: 
        // 1. Digit sum ascending 
        // 2. If digit sums are equal, by the number itself ascending
        sort(vc.begin(), vc.end(), [](const auto& a, const auto& b) {
            if (a.first != b.first) return a.first < b.first;
            return a.second.first < b.second.first;
        });

        // Track visited elements to count cycles
        vector<bool> visited(len, false);
        int cnt = 0;

        for (int i = 0; i < len; i++) {
            // If already visited or already in the correct sorted position, skip
            if (visited[i] || vc[i].second.second == i) {
                continue;
            }

            // Find the size of the cycle
            int cycle_size = 0;
            int j = i;
            while (!visited[j]) {
                visited[j] = true;
                j = vc[j].second.second; // Move to the original index where this element came from
                cycle_size++;
            }

            // If a cycle has 'K' elements, it takes 'K - 1' swaps to fix it
            if (cycle_size > 0) {
                cnt += (cycle_size - 1);
            }
        }

        return cnt;
    }
};

//minimum swaps can be calculated using cycle detection in the permutation
// of indices after sorting based on digit sums. Each cycle of length K
// requires K-1 swaps to sort.

// very important concept