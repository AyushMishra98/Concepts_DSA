    //If we remove a vertex from graph than if the graph is divided into two or more components than its an ARTICULATION POINT
    int timer=1;
    void dfs(int node,int par,vector<bool>& vis,vector<int>adj[],vector<int>& tin,vector<int>& low,vector<int>& mark){
        vis[node]=true;
        tin[node]=low[node]=timer;
        timer++;
        
        int child=0;
        
        for(auto it:adj[node]){
            if(it == par)
                continue;
            
            if(!vis[it]){
                dfs(it,node,vis,adj,tin,low,mark);
                low[node]=min(low[node],low[it]);
                
                if(low[it] >= tin[node] && par != -1)
                    mark[node]=1;
                
                child++;
                    
            }else{
                low[node]=min(low[node],tin[it]);
            }
        }
        if(child > 1 && par==-1)
            mark[node]=1;
    }
    vector<int> articulationPoints(vector<int>adj[],int n) {
        vector<bool> vis(n,false);
        
        vector<int> mark(n,0);
        vector<int> tin(n);
        vector<int> low(n);
        
        for(int  i=0;i<n;i++)
            if(vis[i] == false)
                dfs(i,-1,vis,adj,tin,low,mark);
        
        vector<int> ans;
        for(int i=0;i<n;i++)
            if(mark[i] == 1)
                ans.push_back(i);
        
        if(ans.size() == 0)
            return {-1};
        return ans;
    }
  T.C=O(V+E)
  A.S=O(V+E)
