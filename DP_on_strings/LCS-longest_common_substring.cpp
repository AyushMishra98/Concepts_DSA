int lcs(string &t1, string &t2){
        int n1=t1.length(),n2=t2.length();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
        
        for(int i=0;i<=n1;i++)
            dp[i][0]=0;
        
        for(int i=0;i<=n2;i++)
            dp[0][i]=0;
        
        for(int idx1=1;idx1<=n1;idx1++){
            for(int idx2=1;idx2<=n2;idx2++){
                
                if(t1[idx1-1] == t2[idx2-1])
                    dp[idx1][idx2]=1+dp[idx1-1][idx2-1];
                else
                    dp[idx1][idx2]= 0;
            }
        }
        int maxi=0;
        for(int i=1;i<=n1;i++)
            for(int j=1;j<=n2;j++)
            maxi=max(maxi,dp[i][j]);
        return maxi;
}
//T.C=O(n1*n2)
//A.S=O(n1*n2)
