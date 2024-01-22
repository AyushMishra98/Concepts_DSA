//printing LIS
vector<int> printLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1),hash(n);
        int maxi=1;
        int lastIndex=0;
        
        for(int idx=0;idx<n;idx++){
            hash[idx]=idx;
            for(int prev_idx=0;prev_idx<idx;prev_idx++){
                if(nums[prev_idx] < nums[idx] && dp[idx]<1+dp[prev_idx] ){
                    dp[idx]=1+dp[prev_idx];
                    hash[idx]=prev_idx;
                }
            }
            if(dp[idx] > maxi){
                maxi=dp[idx];
                lastIndex=idx;
            }
        }
        
        vector<int> temp;
        temp.push_back(nums[lastIndex]);
        while(hash[lastIndex] != lastIndex){
            lastIndex=hash[lastIndex];
            temp.push_back(nums[lastIndex]);
        }
        reverse(temp.begin(),temp.end());
        
        
        return temp;
    }
