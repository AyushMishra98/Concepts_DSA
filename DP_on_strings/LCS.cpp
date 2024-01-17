//Recursion 
//T.C=O(2^n * 2^m)

//Memoisation solution
int LCS(int idx1,int idx2,string t1, string t2,vector<vector<int>>& dp){
        if(idx1<0 || idx2<0)
            return 0;
        
        if(dp[idx1-1][idx2-1] == -1){
            if(t1[idx1] == t2[idx2])
            dp[idx1][idx2]=1+LCS(idx1-1,idx2-1,t1,t2,dp);
        else
            dp[idx1][idx2]= max(LCS(idx1-1,idx2,t1,t2,dp),LCS(idx1,idx2-1,t1,t2,dp));
        }
        return dp[idx1][idx2];
    }
    int longestCommonSubsequence(string t1, string t2) {
        int n1=t1.length(),n2=t2.length();
        vector<vector<int>> dp(n1,vector<int>(n2,-1));
        return LCS(n1-1,n2-1,t1,t2,dp);
    }
//T.C=O(n*m)
//A.S=O(n*m)+O(n+m)

//Memoisation solution after shifting idx -done so for tabulation solution 
int LCS(int idx1,int idx2,string t1, string t2,vector<vector<int>>& dp){
        if(idx1 == 0 || idx2 == 0)
            return 0;
        
        if(dp[idx1][idx2] == -1){
            if(t1[idx1-1] == t2[idx2-1])
            dp[idx1][idx2]=1+LCS(idx1-1,idx2-1,t1,t2,dp);
        else
            dp[idx1][idx2]= max(LCS(idx1-1,idx2,t1,t2,dp),LCS(idx1,idx2-1,t1,t2,dp));
        }
        return dp[idx1][idx2];
    }
    int longestCommonSubsequence(string t1, string t2) {
        int n1=t1.length(),n2=t2.length();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
        return LCS(n1,n2,t1,t2,dp);
    }
//T.C=O(n*m)
//A.S=O(n*m)+O(n+m)

//Tabulation solution
int longestCommonSubsequence(string t1, string t2) {
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
                    dp[idx1][idx2]= max(dp[idx1-1][idx2],dp[idx1][idx2-1]);
            }
        }
        return dp[n1][n2];
    }
//T.C=O(n*m)
//A.S=O(n*m)

//Optimal solution
int longestCommonSubsequence(string t1, string t2) {
        int n1=t1.length(),n2=t2.length();

        vector<int> prev(n2+1,0),curr(n2+1,0);
        
//         for(int i=0;i<=n2;i++)
//             prev[i]=0;
        
        for(int idx1=1;idx1<=n1;idx1++){
            for(int idx2=1;idx2<=n2;idx2++){
                
                if(t1[idx1-1] == t2[idx2-1])
                    curr[idx2]=1+prev[idx2-1];
                else
                    curr[idx2]= max(prev[idx2],curr[idx2-1]);
            }
            prev=curr;
        }
        return prev[n2];
    }
//T.C=O(n*m)
//A.S=O(m)
