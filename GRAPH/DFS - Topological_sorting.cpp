void DFSRec(vector<int> adj[],bool vis[],stack<int> &s,int idx){
    vis[idx]=true;
    
    for(auto x:adj[idx])
        if(vis[x]==false)
            DFSRec(adj,vis,s,x);
    s.push(idx);
}
//graph may be disconnected,source may  not be given
void dfsTopologicalSort(vector<int> adj[],int v){
    bool vis[v+1];
    memset(vis,false,sizeof(vis));

    stack<int> s;
    for(int i=0;i<v;i++)
        if(vis[i] == false)
            DFSRec(adj,vis,s,i);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}
