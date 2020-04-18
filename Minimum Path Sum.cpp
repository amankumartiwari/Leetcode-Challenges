class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m= n>0?  grid[0].size():0;
        if(n==0 || m==0)
            return 0;

        vector<vector<int>> help(n , vector<int>(m,0));
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                help[i][j]=0;
            }
        }
        help[n-1][m-1]=grid[n-1][m-1];
       
        for(int i=n-2;i>=0;i--){
            help[i][m-1]=grid[i][m-1]+help[i+1][m-1];
        }
        for(int i=m-2;i>=0;i--){
            help[n-1][i]=grid[n-1][i]+help[n-1][i+1];
        }
        
        for(int i=n-2;i>=0;i--){
            for(int j=m-2;j>=0;j--){
                help[i][j] = grid[i][j] + min(help[i+1][j] , help[i][j+1]);
            }
        }
        
        
        return help[0][0];
    }
}