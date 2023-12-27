void DFSRec(vector<int>& adj[],vector<bool>& vis,stack<int>& st,int s){
    vis[s]=true;
    
    for(auto x:adj[s])
        if(vis[x]==false)
            DFSRec(adj,vis,st,x);
    st.push(s);
}
//graph may be disconnected,source may  not be given
stack<int> dfsTopologicalSort(vector<int>& adj[],int v){
    vector<bool> vis(v,false);
    
    stack<int> st;
    
    for(int i=0;i<v;i++)
        if(vis[i] == false)
            DFSRec(adj,vis,st,i);
    
    return st;
}
