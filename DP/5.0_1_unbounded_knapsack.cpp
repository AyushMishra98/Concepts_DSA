//Tabulation solution
int unboundedKnapsack(int n, int maxW, vector<int> &val, vector<int> &wt){
    vector<vector<int>> dp(n,vector<int> (maxW+1,0));

	for(int w=wt[0];w<=maxW;w++)
		dp[0][w]=((int)(w/wt[0]))*val[0];

	for(int i=1;i<n;i++){
		for(int w=0;w<=maxW;w++){
			int notTake=dp[i-1][w];
			int take=INT_MIN;
			if(wt[i]<= w)
				take=val[i]+dp[i][w-wt[i]];
			dp[i][w]=max(take,notTake);
		}
	}
	return dp[n-1][maxW];
}
//T.C=O(n*maxWt)
//A.S=O(maxWt)
