int prims(vector<pair<int,int>> adj[],int v){
    int key[v];
    fill(key,key+v,INT_MAX);
    key[0]=0;

    bool mset[v]={false};
    int res=0;

    for(int i=0;i<v;i++){
        int u=-1;

        for(int i=0;i<v;i++)
            if(!mset[i] && ((u==-1) || (key[i] < key[u])))
                u=i;
        
        res+=key[u];
        mset[u]=true;
        
        for(auto x:adj[u])
            if(mset[x.first] == false)
                key[x.first]=min(key[x.first],x.second);
    }
    return res;
}
//T.C=O(V*(V+E))=>O(V^2)
//S.C=O(V+E)
