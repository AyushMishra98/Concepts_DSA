void DFSRec(vector<pair<int,int>> adj[],bool vis[],stack<int>& st,int s){
    vis[s]=true;
    
    for(auto x:adj[s])
        if(vis[x.first]==false)
            DFSRec(adj,vis,st,x.first);
    st.push(s);
}
//graph may be disconnected,source may  not be given
void dfsTopologicalSort(vector<pair<int,int>> adj[],int v,stack<int>& st){
    bool vis[v+1];
    memset(vis,false,sizeof(vis));

    for(int i=0;i<v;i++)
        if(vis[i] == false)
            DFSRec(adj,vis,st,i);
}
void shortestPath(vector<pair<int,int>> adj[],int v,stack<int> &st,int s){
    int dist[v];
    for(int i=0;i<v;i++)
        dist[i]=INT_MAX;

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
}
