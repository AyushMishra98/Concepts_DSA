    int timer=1;
    void dfs(int node,int par,vector<bool> &vis,vector<int> adj[],vector<int>& tin,vector<int>& low,vector<vector<int>>& bridges){
        
        vis[node]=true;
        tin[node]=low[node]=timer;
        timer++;
        
        for(auto it:adj[node]){
            if(it == par) continue;
            if(vis[it] == 0){
                dfs(it,node,vis,adj,tin,low,bridges);
                low[node]=min(low[node],low[it]);
                
                if(low[it] > tin[node])
                    bridges.push_back({it,node});
            }
            else{
                low[node]=min(low[node],low[it]);
            }
        }
    }
    vector<vector<int>> bridges(int n,vector<int> adj[]) {
        vector<bool> vis(n,false);
        vector<vector<int>> bridges;
        
        vector<int> tin(n);
        vector<int> low(n);
        
        dfs(0,-1,vis,adj,tin,low,bridges);
        
        return bridges;
    }
    T.C=O(V+E)
    A.S=O(V+E)
