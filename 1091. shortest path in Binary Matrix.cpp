class Solution {
public:
    
    vector<vector<int>> dir = { {-1,-1} ,{-1,0},{-1,1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1} };
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m = n==0?0:grid[0].size();
        
        queue<int> qu;
        if(grid[0][0]==1 || grid[n-1][m-1]==1 || n==0 || m==0)return -1;
        
        qu.push(0);
        grid[0][0]=1;
        int lev=1;
        while(qu.size()!=0){
            
            int sz= qu.size();
            while(sz--){
                int val = qu.front();
                qu.pop();
                int r = val/m ; 
                int c = val%m;
                if(r==n-1 && c==m-1)return lev;
                for(int i=0;i<8;i++){
                 int nr = r + dir[i][0];
                 int nc = c+  dir[i][1];
                    
                    if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==0){
                        grid[nr][nc]=1;
                        qu.push(nr*m + nc );
                    }
                    
                }
                
            }
            lev++;
        }
        return -1;
    }
};