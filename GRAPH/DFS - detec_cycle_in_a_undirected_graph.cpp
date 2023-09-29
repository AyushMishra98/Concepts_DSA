bool DFSRec(vector<int> adj[],bool vis[],int idx,int parent){
    vis[idx]=true;
    for(auto x:adj[idx])
        if(vis[x]==false){
            if(DFSRec(adj,vis,x,idx) == true)
                return true;
        }
        else if(x != parent)//If the element has already came and it again reachable ,so definitely there is a cycle
            return true;
    return false;
}
//graph may be disconnected,source may  not be given
bool DFS(vector<int> adj[],int v){
    bool vis[v+1];
    memset(vis,false,sizeof(vis));

    for(int i=0;i<v;i++)
        if(vis[i] == false)
            if(DFSRec(adj,vis,i,-1) == true) 
                return true;
    return false;
}
//T.C=O(V+E)
//A.s=O(V)
