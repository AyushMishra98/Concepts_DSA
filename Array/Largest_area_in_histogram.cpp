//T.C=O(N)+O(N)
//A.S=O(N)
int largestRectangleArea(vector<int>& h) {
        int n=h.size();
        stack<int> s;
        
        int maxA=0;
        for(int i=0;i<=n;i++){
            while(!s.empty() && (i==n || h[s.top()] >= h[i])){
                
                int height=h[s.top()];
                s.pop();
                
                int width;
                if(s.empty())
                    width=i-0;
                else
                    width=i-s.top()-1;
                
                maxA=max(maxA,height*width);
            }
            s.push(i);
        }
        return maxA;
    }
