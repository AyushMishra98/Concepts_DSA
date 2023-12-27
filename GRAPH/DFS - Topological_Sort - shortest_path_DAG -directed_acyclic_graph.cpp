    void DFSRec(vector<pair<int,int>>& adj[],vector<bool>& vis,stack<int>& st,int s){
    vis[s]=true;
    
    for(auto x:adj[s])
        if(vis[x.first]==false)
            DFSRec(adj,vis,st,x.first);
    st.push(s);
    }
    //graph may be disconnected,source may  not be given
    stack<int> dfsTopologicalSort(vector<pair<int,int>> adj[],int v){
        vector<bool> vis(v,false);
        
        stack<int> st;
        
        for(int i=0;i<v;i++)
            if(vis[i] == false)
               DFSRec(adj,vis,st,i);
        
        return st;
    }
    vector<int> shortestPathDAG(vector<pair<int,int>> adj[],int v,int s){
      vector<int> dist(v,INT_MAX);
    
        stack<int> st=dfsTopologicalSort(adj,v,st);

        dist[s]=0;
        while(!st.empty()){
            
        int curr=st.top();
        st.pop();
        
        if(dist[curr] != INT_MAX){
            for(auto x:adj[curr])
                if(dist[x.first] > dist[curr]+x.second)
                    dist[x.first] = dist[curr]+x.second; 
            }
        }
        return dist;
    }
