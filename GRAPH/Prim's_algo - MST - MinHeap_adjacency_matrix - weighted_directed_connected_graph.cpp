// MST- Minimum spanning tree
// spanning tree - tree with all the vertices with no cycle
int prims(vector<pair<int,int>> adj[],int v){
    bool vis[v]={false};

    //{x1,x2}=> x1-weight ,x2-edge
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,0});

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
            if(vis[x.first] == false)
                pq.push({x.second,x.first});
    }
    return res;
}
T.C = O(V logV)+O((V+E)logV) =>O(ElogV)
S.C = O(V+E)
