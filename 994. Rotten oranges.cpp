class Solution {
public:
    vector<vector<int>> dir = {{-1,0},{0,-1},{1,0},{0,1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m = n==0?0:grid[0].size();
        int ct=0;
        queue<int>qu;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    qu.push(i*m +j);
                }
                if(grid[i][j]==1){
                    ct++;
                }
            }
        }
        int lev=0;
        if(ct==0)return 0;
        while(qu.size()!=0){
            
            int sz = qu.size();
            
            while(sz--){
                 int idx = qu.front();
                qu.pop();
                
                int r = idx/m;
                int c = idx%m;
               
                for(int i=0;i<4;i++){
                    int nr = r+dir[i][0];
                    int nc = c+dir[i][1];
                    
                    if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1){
                        grid[nr][nc]=2;
                        qu.push(nr*m +nc);
                        ct--;
                    }
                    
                }
            }
                         lev++;
            if(ct==0){
                    return lev;
                }

        }
        return -1;
        
    }
};