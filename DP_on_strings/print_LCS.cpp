string longestCommonSubsequence(string t1, string t2) {
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
        int len=dp[n][m];
        string str="";
        for(int i=0;i<len;i++)
          str+='*';

        int idx=len-1;
      int i=n,j=m;
      while(i>0 && j>0){
      if(t1[i-1] == t2[i-1]){
        str[idx]=t1[i-1];
        idx--;i--;j--;
      }
      else if(dp[i-1][j] > dp[i][j-1]){
        i--;
      }
      else{
        j--;
      }
      }
        return str;
    }
