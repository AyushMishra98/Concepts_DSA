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
class Solution
{
    public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
            
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                int u=i;
                int v=it[0];
                int wt=it[1];
                pq.push({wt,{u,v}});
            }
        }
        int res=0;
        DisjointSet ds(V);
        
        while(!pq.empty()){
            auto x=pq.top();
            pq.pop();
            
            int wt=x.first;
            int u=x.second.first;
            int v=x.second.second;
            
            if(ds.findUPar(u) == ds.findUPar(v))
                continue;
                
            ds.unionBySize(u,v);
            res+=wt;
        }
        return res;
        // code here
    }
};
//T.C=O(ElogV)
//A.S=O(V+E)
