bool BFS(vector<vector<int>>& graph,vector<int>& vis,int s){
        queue<int> q;
        q.push(s);
        vis[s]=0;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                
                int temp=q.front();
                q.pop();
                
                for(auto x:graph[temp]){
                    if(vis[x] == -1){
                        vis[x]=!vis[temp];
                        q.push(x);
                    }
                    else{
                        if(vis[x] == vis[temp])
                            return false;
                    }
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int m=graph.size() ,n=graph[0].size();
        vector<int> vis(m,-1);
        for(int i=0;i<m;i++)
            if(vis[i] == -1 && BFS(graph,vis,i) == false)
                return false;
        return true;
    }
