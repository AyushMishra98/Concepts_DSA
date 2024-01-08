//all pair shortest path - Floyd Warshall algorithm
void shortest_distance(vector<vector<int>>&m){
	    int n=m.size();
	    for(int i=0;i<n;i++)
	        for(int j=0;j<n;j++)
	            if(m[i][j] == -1)
	                m[i][j]=1e9;
	                
	   for(int k=0;k<n;k++){
	       for(int i=0;i<n;i++){
	           for(int j=0;j<n;j++){
	               m[i][j]=min(m[i][j],m[i][k]+m[k][j]);
	           }
	       }
	   }
	   for(int i=0;i<n;i++)
	        for(int j=0;j<n;j++)
	            if(m[i][j] == 1e9)
	                m[i][j]=-1;
	}
//adjacency matrix representation
//T.C=O(n^3)
//A.S=O(n^2)
