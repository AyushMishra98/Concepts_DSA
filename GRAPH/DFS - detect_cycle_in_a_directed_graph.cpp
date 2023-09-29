bool DFSRec(vector<int> adj[],bool vis[],bool anc[],int idx){
    vis[idx]=true;
    anc[idx]=true;
    
    for(auto x:adj[idx])
        if(vis[x]==false && DFSRec(adj,vis,anc,x))
            return true;
        else if(anc[x]==true)
            return true;
    anc[idx]=false;
    return false;
}
//graph may be disconnected,source may  not be given
bool DFS(vector<int> adj[],int v){
    bool vis[v+1];
    bool anc[v+1];//ancestors
    memset(vis,false,sizeof(vis));
    memset(anc,false,sizeof(anc));

    for(int i=0;i<v;i++)
        if(vis[i] == false)
            if(DFSRec(adj,vis,anc,i)==true)
                return true;
    return false;
}
//T.C=O(V+E)
//S.C=O(V)
