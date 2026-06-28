// subset problem on leetcode
// it can be solved using backtracking approach
// where we can take or not take the element in the
// subset and then we can move to next index and repeat
// the process until we reach the end of the array.

class Solution {
public:

    void helper(int idx, vector<int>& nums, int n, vector<int>temp, vector<vector<int>>& ans){
        if(idx == n){
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[idx]);
        helper(idx+1, nums, n, temp, ans);  //not_take case;
        temp.pop_back();
        helper(idx+1, nums, n, temp, ans);  // take case;
        return;
        
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        int n = nums.size();
        helper(0,nums,n,temp, ans);
        return ans;
    }
};