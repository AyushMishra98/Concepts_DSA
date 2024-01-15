bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>> dp(n,vector<bool> (k+1,false));
    for(int i=0;i<n;i++)
        dp[i][0]=true;
    
    dp[0][arr[0]]=true;

    for(int i=1;i<n;i++){
        for (int t = 0; t <= k; t++) {

          dp[i][t] = dp[i - 1][t];
          if (arr[i] <= t)
            dp[i][t] = dp[i][t] || dp[i - 1][t - arr[i]];
        }
    }
    return dp[n-1][k];
}
//T.C=O(N*target)
//A.S=O(N)
