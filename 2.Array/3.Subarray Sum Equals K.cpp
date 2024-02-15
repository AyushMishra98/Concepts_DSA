int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> prevsum;
        
        int res=0;
        int currsum=0;
  
        for(int i=0;i<nums.size();i++){
            currsum+=nums[i];
            if(currsum==k)
                res++;
            if(prevsum.find(currsum-k)!=prevsum.end())
                res+=prevsum[currsum-k];
            
            prevsum[currsum]++;
        }
        return res;
    }
