//graph had to be DAG
void topologicalSort(vector<int> adj[],int v){
    int indgre[v];
    memset(indgre,0,sizeof(indgre));
    
    for(int i=0;i<v;i++)
        for(auto x:adj[i])
            indgre[x]++;
    queue<int> q;
    for(int i=0;i<v;i++)
        if(indgre[i] == 0)
            q.push(i);
    while(!q.empty()){
        int temp=q.front();
        q.pop();
        
        cout<<temp<<" ";
        
        for(auto x:adj[temp]){
            indgre[x]--;
            if(indgre[x] == 0)
                q.push(x);
        }
        
    }
}
//T.C=O(V+E)
//S.C=O(V)
