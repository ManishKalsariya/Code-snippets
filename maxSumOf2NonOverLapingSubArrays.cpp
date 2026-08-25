//Leetcode 1031. Maximum Sum of Two Non-Overlapping Subarrays


class Solution {
public:
    vector<int> pref(vector<int>nums){
        int n = nums.size();
        vector<int>pre(n);
        int sm = 0;
        for(int i=0; i<n; i++){

            sm += nums[i];
            pre[i] = sm;
        }
        return pre;
    }

    vector<int> suff(vector<int>nums){
        int n = nums.size();
        int sm = 0;
        vector<int>suf(n);
        for(int i=n-1; i>=0; i--){
            sm += nums[i];
            suf[i]=  sm;
        }
        return suf;
    }

    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        vector<int>pre = pref(nums);
        vector<int>suf = suff(nums);

        int mx = 0;

        int n = nums.size();

        // firstOne is first Length subarray;
        for(int i = firstLen - 1; i < n - secondLen; i++){
            int sum1 = pre[i] - (i - firstLen >= 0 ? pre[i - firstLen] : 0);

          
            for(int j = i + 1; j <= n - secondLen; j++){
                int sum2 = suf[j] - (j + secondLen < n ? suf[j + secondLen] : 0);
                mx = max(mx, sum1 + sum2);
            }
        }

        //firstOne is second length subArray;
        for(int i = secondLen - 1; i < n - firstLen; i++){
            int sum1 = pre[i] - (i - secondLen >= 0 ? pre[i - secondLen] : 0);

            for(int j = i + 1; j <= n - firstLen; j++){
                int sum2 = suf[j] - (j + firstLen < n ? suf[j + firstLen] : 0);
                mx = max(mx, sum1 + sum2);
            }
        }
        return mx;



    }
};