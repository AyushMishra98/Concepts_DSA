//BFS based
// v-no. of vertices (size of adj)
vector<int> shortestPath(vector<int> adj[],int v,int s){
    vector<bool> vis(v,false);
    vector<int> dist(v,INT_MAX);

    queue<int> q;
    q.push(s);

    vis[s]=true;
    dist[s]=0;//dist of a vertex from itself to itself will be zero
    while(!q.empty()){
        int temp=q.front();
        q.pop();
        for(auto x:adj[temp]){
            if(vis[x] == false){
                dist[x]=min(dist[x],1+dist[temp]);
                vis[x]=true;
                q.push(x);
            }
        }
    }
    return dist;
}
//T.C=O(V+E)
//A.S=O(V)
