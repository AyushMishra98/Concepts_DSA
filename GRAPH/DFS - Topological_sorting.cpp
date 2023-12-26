void DFSRec(vector<int> adj[],bool vis[],stack<int> &st,int s){
    vis[s]=true;
    
    for(auto x:adj[s])
        if(vis[x]==false)
            DFSRec(adj,vis,st,x);
    st.push(idx);
}
//graph may be disconnected,source may  not be given
void dfsTopologicalSort(vector<int> adj[],int v){
    bool vis[v+1];
    memset(vis,false,sizeof(vis));

    stack<int> st;
    for(int i=0;i<v;i++)
        if(vis[i] == false)
            DFSRec(adj,vis,st,i);
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}
