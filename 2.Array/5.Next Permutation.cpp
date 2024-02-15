    void nextPermutation(vector<int>& nums) {
        //next_permutation(nums.begin(),nums.end());
        int n=nums.size();
        int idx=-1;
        //finding the break point
        for(int i=n-2;i>=0;i--)
            if(nums[i]<nums[i+1]){
                idx=i;
                break;
            }
        //swapping value of num at idx with least greater element on right side 
        if(idx!=-1){
            for(int i=n-1;i>idx;i--)
                if(nums[i]>nums[idx]){
                    swap(nums[idx],nums[i]);
                    break;
            }
        }
        //Sorted at specific index if break point is found else whole array is sorted 
        //-1+1=0
        reverse(nums.begin()+idx+1,nums.end());
        //T.C=O(N)
        //S.c=O(1)
    }
