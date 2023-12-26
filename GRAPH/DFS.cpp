void DFSRec(vector<int> adj[],bool vis[],int s){
    vis[s]=true;
    for(auto x:adj[s])
        if(vis[x]==false)
            DFSRec(adj,vis,x);
}
//graph may be disconnected,source may  not be given
void DFS(vector<int> adj[],int v){
    bool vis[v+1];
    memset(vis,false,sizeof(vis));

    for(int i=0;i<v;i++)
        if(vis[i] == false)
            DFSRec(adj,vis,i);
}
//T.C=O(V+E)
//A.s=O(V)
