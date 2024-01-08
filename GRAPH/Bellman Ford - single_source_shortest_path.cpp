//Bellman Ford is a SINGLE SOURCE SHORTEST PATH
//Bellman Ford helps in FINDING NEGATIVE CYCLES IN DIRECTED GRAPH
//works for only directed graphs
//to apply for undirected graph convert to directed graph

vector<int> bellman_ford(int V, vector<vector<int>>& e, int S) {
        vector<int> dist(V,1e8);
        dist[S]=0;
        
        for(int i=0;i<V-1;i++){
            for(auto x:e){
                
                int u=x[0];
                int v=x[1];
                int wt=x[2];
                
                if(dist[u]!=1e8 && dist[u]+wt<dist[v])
                    dist[v] = dist[u]+wt;
            }
        }
        for(auto x:e){
                
                int u=x[0];
                int v=x[1];
                int wt=x[2];
                
                if(dist[u]!=1e8 && dist[u]+wt<dist[v])
                    return {-1};
            }
        return dist;
    }
//T.C=O(V*E)
//S.C=O(V+E)
