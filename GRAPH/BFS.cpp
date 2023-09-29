void  BFS(vector<int> adj[],int v,int s,bool visited[]){
    queue<int> q;
    
    visited[s]=true;
    q.push(s);

    while(!q.empty()){
        int u=q.front();
        q.pop();

        cout<<u<<" ";
        
        for(auto x:adj[u])
            if(visited[x] == false){
                q.push(x);
                visited[x]=true;
            }
    }
    cout<<endl;
}
//graph may be disconnected ,source may not be given
void BFSdis(vector<int> adj[],int v){
    // v-size of adj
    bool visited[v+1];
    memset(visited,false,sizeof(visited));
    
    //traversing all elemets to check whether visited or not
    for(int i=0;i<v;i++)
        if(visited[i] == false)
            BFS(adj,v,i,visited);
}
//T.C=O(V+E)
//A.S=O(V)
