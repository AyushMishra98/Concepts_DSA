//works for both directed and undirected graph 
//used to find shortest path
vector<int> dijkstra(vector<pair<int,int>> adj[],int v,int src){
    bool vis[v]={false};
    vector<int> dist(v,INT_MAX);
    //{x1,x2}=> x1-weight ,x2-edge
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,src});
    dist[src]=0;

    int res=0;

    while(!pq.empty()){
        auto curr=pq.top();
        pq.pop();
        
        int wt=curr.first;
        int u=curr.second;

        if(vis[u] == true)
            continue;
        res+=wt;
        vis[u]=true;

        for(auto x:adj[u])
            if(vis[x.first] == false && dist[x]>dist[u]+x.second)
                pq.push({dist[u]+x.second,x.first});
    }
    return dist;
}
T.C = O(V logV)+O((V+E)logV) =>O(ElogV)
S.C = O(V+E)
