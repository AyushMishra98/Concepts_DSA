int countSubsetsToK(vector<int>& arr, int k)
{
	int mod=1e9+7;
	int n=arr.size();
	vector<vector<int>> dp(n,vector<int> (k+1,0));
	for(int i=0;i<n;i++)
		dp[i][0]=1;
	if(arr[0]<=k)
		dp[0][arr[0]]+=1;
	for(int i=1;i<n;i++){
		for(int t=0;t<=k;t++){
			int notTake=dp[i-1][t];
			int take=0;
			if(arr[i] <= t)
				take=dp[i-1][t-arr[i]];
				
		dp[i][t]=(take+notTake)%mod;
		
		}
	}
	return dp[n-1][k];
	// Write your code here.
}
