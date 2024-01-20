//Longest Increasing subsequence

//Recursion
//T.C=O(2^n)
//A.S=O(n)
int LIS(int idx,int prev_idx,vector<int>& nums){
        if(idx == nums.size())
            return 0;
        
        int len=LIS(idx+1,idx,nums);
        if(prev_idx == -1 || nums[idx]>nums[prev_idx])
            len=max(len,1+LIS(idx+1,idx,nums));
        return len;
    }
    int lengthOfLIS(vector<int>& nums) {
        return LIS(0,-1,nums);
    }
