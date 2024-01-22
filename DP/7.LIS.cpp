//Longest Increasing subsequence

//Recursion
//T.C=O(2^n)
//A.S=O(n)
int LIS(int idx,int prev_idx,vector<int>& nums){
        if(idx == nums.size())
            return 0;
        
        int len=LIS(idx+1,prev_idx,nums);
        if(prev_idx == -1 || nums[idx]>nums[prev_idx])
            len=max(len,1+LIS(idx+1,idx,nums));
        return len;
    }
    int lengthOfLIS(vector<int>& nums) {
        return LIS(0,-1,nums);
    }
//Tabulation solution
int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        int maxi=1;
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(nums[prev] < nums[i])
                    dp[i]=max(dp[i],1+dp[prev]);
            }
            maxi=max(maxi,dp[i]);
        }
        return maxi;
    }
//T.C=O(n*n)
//A.S=O(n)
