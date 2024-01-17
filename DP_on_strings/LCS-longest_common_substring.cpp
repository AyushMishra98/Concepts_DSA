//variation of LCS just make dp part of else equal to zero rather than storing maximum
int lcs(string &t1, string &t2){
        int n1=t1.length(),n2=t2.length();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
        
        for(int i=0;i<=n1;i++)
            dp[i][0]=0;
        
        for(int i=0;i<=n2;i++)
            dp[0][i]=0;
        
        int maxi=0;
        for(int idx1=1;idx1<=n1;idx1++){
            for(int idx2=1;idx2<=n2;idx2++){
                
                if(t1[idx1-1] == t2[idx2-1]){
                        dp[idx1][idx2]=1+dp[idx1-1][idx2-1];
                        maxi=max(maxi,dp[idx1][idx2]);
                }
                else
                    dp[idx1][idx2]= 0;
            }
        }
        return maxi;
}
//T.C=O(n1*n2)
//A.S=O(n1*n2)

//Optimal solution
int lcs(string &t1, string &t2){
        int n1=t1.length(),n2=t2.length();

        vector<int> prev(n2+1,0),curr(n2+1,0);
        
//         for(int i=0;i<=n2;i++)
//             prev[i]=0;
        int maxi=0;
        for(int idx1=1;idx1<=n1;idx1++){
            for(int idx2=1;idx2<=n2;idx2++){
                
                if(t1[idx1-1] == t2[idx2-1]){
                    curr[idx2]=1+prev[idx2-1];
                    maxi=max(maxi,curr[idx2]);
                }
                else{
                    curr[idx2]=0;
                }
                
            }
            prev=curr;
        }
        return maxi;
}
//T.C=O(n1*n2)
//A.S=O(n2)
