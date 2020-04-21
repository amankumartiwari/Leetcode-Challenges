class Solution {
public:
    int n,m;
    
    int helper( vector<vector<int>>& grid , int i ,int  j ){
        
        grid[i][j]=0;
        int ans=0;
        if(i-1>=0 && grid[i-1][j]==1 )
           ans+= helper(grid , i-1,j);
        if(j-1>=0 && grid[i][j-1]==1 )
           ans+= helper(grid , i,j-1);
        if(i+1<n && grid[i+1][j]==1 )
           ans+= helper(grid , i+1,j);
        if(j+1<m && grid[i][j+1]==1 )
           ans+= helper(grid , i,j+1);
        
        return ans+1;
        
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        n=grid.size();
        m = n==0?0:grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                  ans= max(ans, helper(grid ,i,j) );
                }
            }
        }
        return ans;
    }
};