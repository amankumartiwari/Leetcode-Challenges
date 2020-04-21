class Solution {
public:
   int n,m;
    void helper(vector<vector<int>>& A , int  i ,int j){
        
        A[i][j]=0;
        
        if(i-1>=0 && A[i-1][j]==1){
            helper(A,i-1,j);
        }
        if(j-1>=0 && A[i][j-1]==1){
            helper(A,i,j-1);
        }
        if(i+1<n && A[i+1][j]==1){
            helper(A,i+1,j);
        }
        if(j+1<m && A[i][j+1]==1){
            helper(A,i,j+1);
        }
        
    }
    
    int numEnclaves(vector<vector<int>>& A) {
         n=A.size();
         m=n==0?0:A[0].size();
        
        for(int i=0;i<n;i++){
            if(A[i][0]==1){
                helper(A,i,0);
            }
            if(A[i][m-1]==1){
                helper(A , i,m-1);
            }
        }
        for(int i=1 ;i<m-1;i++){
            if(A[0][i]==1){
                helper(A,0,i);
            }
            if(A[n-1][i]==1){
                helper(A,n-1,i);
            }
        }
        
        int ct=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(A[i][j]==1)ct++;
            }
        }
        
        
        return ct;
    }
};