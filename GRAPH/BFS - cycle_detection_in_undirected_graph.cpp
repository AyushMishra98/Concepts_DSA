//T.C=O(V+E)
//A.S=O(V)
bool BFScycle(vector<int> adj[],int s,bool vis[]){
    vis[s]=true;
    queue<pair<int,int>> q;
    q.push({s,-1});
    while(!q.empty()){
        int sz=q.size();
        for(int i=0;i<sz;i++){
            auto temp=q.front();
            q.pop();

            int node=temp.first;
            int par=temp.second;
            
            for(auto x:adj[node]){
                if(vis[x] == false){
                    q.push({x,node});
                     vis[x]=true;
                }
                else if(x != par)
                    return true;
            }
        }
    }
    return false;
}
bool BFSdis(vector<int> adj[],int v){
    bool vis[v+1];
    memset(vis,false,sizeof(vis));
    for(int i=0;i<v;i++)
        for(auto x:adj[i])
            if(vis[x] == false){
                if(BFScycle(adj,x,vis))
                    return true;
            }
    return false;
}
