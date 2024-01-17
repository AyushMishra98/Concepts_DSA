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
