//Memoization solution
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
