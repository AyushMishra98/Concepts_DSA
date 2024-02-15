int maxSubArray(vector<int>& nums) {
       
        int sum=nums[0],maxi=nums[0];
        for(int i=1;i<nums.size();i++){
            sum=max(sum+nums[i],nums[i]);
            maxi=max(maxi,sum);
        }
        return maxi;
    }
