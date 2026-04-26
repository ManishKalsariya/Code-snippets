// for matrix chain multiplication problems...

//memoiation method : 


int f(int i, int j, vector<int>&arr, vector<int>&dp){
    if(i == j) return 0;

    if(dp[i][j] != -1) return dp[i][j];
    int mini = 1e9;
    for(int k=i; k<j; k++){
        int steps = arr[i-1]*arr[k]*arr[j] + f(i,k,arr,dp) + f(k+1,j,arr,dp);
        if(mini > steps) mini = steps;
    }
    return dp[i][j] = mini;
}

int matrixMultiplication(vector<int>&arr, int n){
    vector<vector<int>>dp(n,vector<int>(n,-1));

    return f(1,n-1,arr,dp);
}

// Tablation method : 

int matrixMultiplication(vector<int>&arr, int n){
    vector<vector<int>>dp(n,vector<int>(n,0));

    for(int i=n-1; i>=1 i--){
        for(int j=i+1; j<n; j++){

            int mini = 1e9;
            for(int k=i; k<j; k++){
                int steps = arr[i-1]*arr[k]*arr[j] + dp[i][k] + dp[k+1][j];
                if(mini > steps) mini = steps;
            }
            dp[i][j] = mini;

        }
    }

    return dp[1][n-1];
}