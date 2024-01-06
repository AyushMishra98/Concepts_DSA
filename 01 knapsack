//Dynamic Programming
vector<int> dp;
    int getProfit(vector<vector<int>>& job,vector<int>& startTime,int idx){
        if(idx >= job.size())
            return 0;
        
        if(dp[idx] == -1){
            //picking the element
            int i=lower_bound(startTime.begin(),startTime.end(),job[idx][1])-startTime.begin();
            int pick=job[idx][2]+getProfit(job,startTime,i);
            //not picking
            int notpick=getProfit(job,startTime,idx+1);
            dp[idx]=max(pick,notpick);
        }
        return dp[idx];
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=startTime.size();
        dp.resize(n,-1);
        
        vector<vector<int>> job;
        for(int i=0;i<n;i++)
            job.push_back({startTime[i],endTime[i],profit[i]});
        
        sort(job.begin(),job.end());
        sort(startTime.begin(),startTime.end());
        
        return getProfit(job,startTime,0);
    }
