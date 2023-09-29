void DFSRec(vector<pair<int,int>> adj[],bool vis[],stack<int> &s,int idx){
    vis[idx]=true;
    
    for(auto x:adj[idx])
        if(vis[x.first]==false)
            DFSRec(adj,vis,s,x.first);
    s.push(idx);
}
//graph may be disconnected,source may  not be given
void dfsTopologicalSort(vector<pair<int,int>> adj[],int v,stack<int> &s){
    bool vis[v+1];
    memset(vis,false,sizeof(vis));

    for(int i=0;i<v;i++)
        if(vis[i] == false)
            DFSRec(adj,vis,s,i);
}
void shortestPath(vector<pair<int,int>> adj[],int v,stack<int> &s,int src){
    int dist[v];
    for(int i=0;i<v;i++)
        dist[i]=INT_MAX;

    dist[src]=0;
    while(!s.empty()){
        int curr=s.top();
        s.pop();
        if(dist[curr] != INT_MAX){
            for(auto x:adj[curr])
                if(dist[x.first] > dist[curr]+x.second)
                    dist[x.first] = dist[curr]+x.second; 
        }
    }
    for(auto x:dist)
        cout<<x<<" ";
    cout<<endl;
}
