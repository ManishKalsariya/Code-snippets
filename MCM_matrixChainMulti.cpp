 // matrix chain multiplication problem on geeksforgeeks 
 // is solved using recursion and memoization. The time complexity
 // of this solution is O(n^3) and space complexity is O(n^2).
 
 
 int function(vector<int>& arr, int i, int j, vector<vector<int>>& dp){
        if(j == i+1){
            return 0;
        }
        
        int res = INT_MAX;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        for(int k=i+1; k<j; k++){
            int curr = function(arr, i, k, dp) + function(arr, k, j, dp) + arr[i]*arr[k]* arr[j];
            res = min(res,curr);
        }
        return dp[i][j] = res;
    }
  
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        return function(arr, 0 , n-1, dp);
        
    }
};