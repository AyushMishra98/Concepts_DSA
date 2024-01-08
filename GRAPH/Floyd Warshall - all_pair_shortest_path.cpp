//all pair shortest path - Floyd Warshall algorithm
void shortest_distance(vector<vector<int>>&m){
	//non reachable nodes are represented with 1e9 instead of -1
	    int n=m.size();
	                
	   for(int k=0;k<n;k++){
	       for(int i=0;i<n;i++){
	           for(int j=0;j<n;j++){
	               m[i][j]=min(m[i][j],m[i][k]+m[k][j]);
	           }
	       }
	   }
	}
//adjacency matrix representation
//T.C=O(n^3)
//A.S=O(n^2)
