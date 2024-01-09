//T.C=O(4α)=constant time
class DisjointSet{
    
    public:
    vector<int> rank,parent;

    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<n+1;i++)
            parent[i]=i;
    }
    int findUPar(int node){
        if(node == parent[node])
            return node;
        return parent[node]=findUPar(parent[node]);
    }
    void unionByRank(int u,int v){
        int ulp_u=parent[u];
        int ulp_v=parent[v];

        if(ulp_u == ulp_v)
            return;
        if(rank[ulp_u] < rank[ulp_v])
            parent[ulp_u]=ulp_v;
        else if(rank[ulp_v] < rank[ulp_u])
            parent[ulp_v]=ulp_u;
        else{
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }
};
