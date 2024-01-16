//𝐌𝐞𝐦𝐨𝐢𝐳𝐚𝐭𝐢𝐨𝐧 𝐬𝐨𝐥𝐮𝐭𝐢𝐨𝐧
int maxVal(int idx,int maxW,vector<int>& w, vector<int>& v,vector<vector<int>>& dp){
	if(idx == 0){
		if(w[0] <= maxW)
			return v[0];
		else
			return 0;
	}
	if(dp[idx][maxW] == -1){
		int notTake=maxVal(idx-1,maxW,w,v,dp);
		int take=INT_MIN;
		if(w[idx]<= maxW)
			take=v[idx]+maxVal(idx-1,maxW-w[idx],w,v,dp);
		dp[idx][maxW]=max(take,notTake);
	}
	return dp[idx][maxW];
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>> dp(n,vector<int> (maxWeight+1,-1));
	return maxVal(n-1,maxWeight,weight,value,dp);
}
//T.C=O(N*maxW)
//A.S=O(N*maxW)+O(N)

//𝐓𝐚𝐛𝐮𝐥𝐚𝐭𝐢𝐨𝐧 𝐬𝐨𝐥𝐮𝐭𝐢𝐨𝐧
int knapsack(vector<int> wt, vector<int> val, int n, int maxW) 
{
	vector<vector<int>> dp(n,vector<int> (maxW+1,0));

	for(int w=wt[0];w<=maxW;w++)
		dp[0][w]=val[0];

	for(int i=1;i<n;i++){
		for(int w=0;w<=maxW;w++){
			int notTake=dp[i-1][w];
			int take=INT_MIN;
			if(wt[i]<= w)
				take=val[i]+dp[i-1][w-wt[i]];
			dp[i][w]=max(take,notTake);
		}
	}
	return dp[n-1][maxW];
}
//T.C=O(N*maxW)
//A.S=O(N*maxW)

//𝐒.𝐂=𝐎(𝐦𝐚𝐱𝐖𝐞𝐢𝐠𝐡𝐭) 𝐨𝐫 𝐥𝐢𝐧𝐞𝐚𝐫 𝐬𝐨𝐥𝐮𝐭𝐢𝐨𝐧
int knapsack(vector<int> wt, vector<int> val, int n, int maxW) 
{
	vector<int> prev(maxW+1,0),curr(maxW+1,0);

	for(int w=wt[0];w<=maxW;w++)
		prev[w]=val[0];

	for(int i=1;i<n;i++){
		for(int w=0;w<=maxW;w++){
			int notTake=prev[w];
			int take=INT_MIN;
			if(wt[i]<= w)
				take=val[i]+prev[w-wt[i]];
			curr[w]=max(take,notTake);
		}
		prev=curr;
	}
	return prev[maxW];
}
//T.C=O(N*maxW)
//A.S=O(maxW)
