//Memoisation
int maxPrice(int idx,int n,vector<int> &p,vector<vector<int>>& dp){
    if(idx == 0)
        return p[idx]*n;

    if(dp[idx][n] == -1){
        
        int notTake=maxPrice(idx-1,n,p,dp);
        int take=0;
        if(idx+1 <= n)
            take=p[idx]+maxPrice(idx,n-idx-1,p,dp);
        
        dp[idx][n]=max(take,notTake);
    }
    
    return dp[idx][n];
}
int cutRod(vector<int> &price, int n){
    vector<vector<int>> dp(n,vector<int> (n+1,-1));
    return maxPrice(n-1,n,price,dp);
}
//T.C=O(n*n)
//A.S=O(n*n)+O(n)

//Tabulation
int cutRod(vector<int> &p, int n){
    vector<vector<int>> dp(n,vector<int> (n+1,0));

    for(int amt=1;amt<=n;amt++)
        dp[0][amt]=amt*p[0];

    for(int idx=1;idx<n;idx++){
        for(int amt=0;amt<=n;amt++){

            int notTake=dp[idx-1][amt];
            int take=0;
            if(idx+1 <= amt)
                take=p[idx]+dp[idx][amt-idx-1];
            dp[idx][amt]=max(take,notTake);
        }
    }
    return dp[n-1][n];
}
//T.C=O(n*n)
//A.S=O(n*n)

//Optimal solution
int cutRod(vector<int> &p, int n){

    vector<int> prev(n+1,0),curr(n+1,0);
    for(int amt=1;amt<=n;amt++)
        prev[amt]=amt*p[0];

    for(int idx=1;idx<n;idx++){
        for(int amt=0;amt<=n;amt++){

            int notTake=prev[amt];
            int take=0;
            if(idx+1 <= amt)
                take=p[idx]+curr[amt-idx-1];
            curr[amt]=max(take,notTake);
        }
        prev=curr;
    }
    return prev[n];
}
//T.C=O(n*n)
//A.S=O(n)
