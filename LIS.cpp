// longest increaasing subsequence...(just for size, temp vector which we are getting is not LIS)

int longestIncreasingSubsequence(vector<int>&nums){

    vector<int>temp;
    int n = nums.size();
    temp.push_back(nums[0]);
    
    for(int i=1; i<n; i++){
        if(nums[i] >= temp.back()) temp.push_back(nums[i]);
        else{
            int ind = lower_bound(temp.begin(), temp.end(), nums[i]);
            temp[ind] = nums[i];
        }
    }
    return temp.size();
}

// printing LIS

vector<int> longestIncreasingSubsequence(vector<int>&nums){

    int n = nums.size();
    int lastIndex = 0;
    int maxi = 1;
    vector<int>hash(n);
    vector<int>dp(n,1);

    for(int i=0; i<n; i++){
        hash[i] = i;
        for(int prev = 0; prev<i; prev++){


            if(nums[prev] <= nums[i] && 1+dp[prev] > dp[i]){
                dp[i] = 1 + dp[prev];
                hash[i] = prev;
            }

        }

        if(dp[i] > maxi ){
            maxi = dp[i];
            lastIndex = i;
        }
    }

    vector<int>temp;
    temp.push_back(nums[lastIndex]);

    while(hash[lastIndex] != lastIndex){
        lastIndex = hash[lastIndex];
        temp.push_back(nums[lastIndex]);
    }

    reverse(temp.begin(),temp.end());

    return temp;


}