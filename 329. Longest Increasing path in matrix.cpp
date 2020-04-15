class Solution {
public:
    int n,m;
    int dfs(vector<vector<int>>& matrix , vector<vector<int>>& dp,int i , int j,int val ){
        
        int a=0,b=0,c=0,d=0;
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
       if(j+1<m && matrix[i][j+1]>val){
          a= dfs(matrix,dp,i,j+1,matrix[i][j+1]);
       } 
        
        if(j-1>=0  &&matrix[i][j-1]>val){
            b= dfs(matrix,dp,i,j-1,matrix[i][j-1]);
        }
        
        if(i+1<n && matrix[i+1][j]>val){
            c=dfs(matrix,dp,i+1,j,matrix[i+1][j]);
        }
        if(i-1>=0  &&matrix[i-1][j]>val){
            d= dfs(matrix,dp,i-1,j,matrix[i-1][j]);
        }
        
        dp[i][j]=1+ max(a,max(b,max(c,d)));
        return dp[i][j];
        
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n=matrix.size();
        if(n==0)return 0;
        m=matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int ans=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dp[i][j]==-1){
                   int a = dfs(matrix , dp, i,j,matrix[i][j]);
                   ans=max(ans,a);
                }
            }
        }
        
        return ans;
    }
};