void DFSRecTopologicalSort(vector<int> adj[],bool vis[],stack<int> &s,int idx){
    vis[idx]=true;
    
    for(auto x:adj[idx])
        if(vis[x]==false)
            DFSRecTopologicalSort(adj,vis,s,x);
    s.push(idx);
}
//graph may be disconnected,source may  not be given
void dfsTopologicalSort(vector<int> adj[],int v,stack<int> &s){
    bool vis[v+1];
    memset(vis,false,sizeof(vis));

    for(int i=0;i<v;i++)
        if(vis[i] == false)
            DFSRecTopologicalSort(adj,vis,s,i);
}
void DFSRec(vector<int> adjT[],bool vis[],int idx){
    vis[idx]=true;
    cout<<idx<<" ";

    for(auto x:adjT[idx])
        if(vis[x]==false)
            DFSRec(adjT,vis,x);
    
}
void DFS(vector<int> adjT[],int v,stack<int> &s){
    bool vis[v]={false};
        while(!s.empty()){
            int idx=s.top();
            if(vis[idx] == false){
                    DFSRec(adjT,vis,idx);
                    cout<<endl;
                }
            s.pop();
        }
}
void stronglyConnectedComponent(vector<int> adj[],vector<int> adjT[],int v){
    //adj-adjacency matrix
    //adjT-transpose of adjacency matrix
    stack<int> s;
    dfsTopologicalSort(adj,v,s);
    DFS(adjT,v,s);
}
