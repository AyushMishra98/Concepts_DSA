int majorityElement(vector<int>& nums) {
        int res=0,count=1;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i] == nums[res])
                count++;
            else
                count--;
            if(count == 0){
                res=i;
                count=1;
            }
        }
        count=0;
        for(int i=0;i<n;i++)
            if(nums[i] == nums[res])
                count++;
        if(count > n/2)
            return nums[res];
        return -1;
    }
