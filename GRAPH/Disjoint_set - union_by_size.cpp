//Union by size makes more sense than union by rank
class DisjointSet{
    vector<int> size,parent;
    public:
    
    DisjointSet(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<n+1;i++)
            parent[i]=i;
    }
    int findUPar(int node){
        if(node == parent[node])
            return node;
        return parent[node]=findUPar(parent[node]);
    }
    void unionBySize(int u,int v){
        int ulp_u=parent[u];
        int ulp_v=parent[v];

        if(ulp_u == ulp_v)
            return;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};
//T.C=O(4*alpha)=constant time
//ds.DisjointSet(n);
//ds.unionBysize(n1,n2);
//ds.findUPar(x);