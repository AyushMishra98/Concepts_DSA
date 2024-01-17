//infinite supply or multiple use of coins

//Memoisation solution
int countCoins(int idx,int amt,vector<int>& c,vector<vector<int>>& dp){
        if(idx == 0){
            if(amt%c[idx] == 0)
                return (amt/c[idx]);
            else
                return 1e9;
        }
        if(dp[idx][amt] == -1){
        
        int notTake=countCoins(idx-1,amt,c,dp);
        
        int take=INT_MAX;
        if(c[idx]<=amt)
            take=1+countCoins(idx,amt-c[idx],c,dp);
        
        dp[idx][amt]=min(take,notTake);
        }
        return dp[idx][amt];
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,-1));
        
        int temp=countCoins(coins.size()-1,amount,coins,dp);
            if(temp>=1e9)
                return -1;
        return temp;
    }

//Tabulation
int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,0));
        
        for(int amt=0;amt<=amount;amt++)
            if(amt%coins[0] == 0)
                dp[0][amt]=amt/coins[0];
            else
                dp[0][amt]=1e9;
        for(int idx=1;idx<n;idx++){
            for(int amt=0;amt<=amount;amt++){
            int notTake=dp[idx-1][amt];
            
            int take=INT_MAX;
            if(coins[idx]<=amt)
                take=1+dp[idx][amt-coins[idx]];
            
            dp[idx][amt]=min(take,notTake);
            }
        }        
        return (dp[n-1][amount] >= 1e9)?-1:dp[n-1][amount];
    }

//optimal solution
int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<int> prev(amount+1,0),curr(amount+1,0);
        
        for(int amt=0;amt<=amount;amt++)
            if(amt%coins[0] == 0)
                prev[amt]=amt/coins[0];
            else
                prev[amt]=1e9;
        for(int idx=1;idx<n;idx++){
            for(int amt=0;amt<=amount;amt++){
            int notTake=prev[amt];
            
            int take=INT_MAX;
            if(coins[idx]<=amt)
                take=1+curr[amt-coins[idx]];
            
            curr[amt]=min(take,notTake);
            }
            prev=curr;
        }        
        return (prev[amount] >= 1e9)?-1:prev[amount];
    }
//T.C=O(N*target)
//A.S=O(target)
