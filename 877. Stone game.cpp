class Solution {
public:
    
    int helper(vector<int>&piles , vector<vector<int>>&dp , bool bari,int s ,int e ){
        
        if(s>e){
           // dp[s][e]=0;
            return 0;
        }
        
        if(dp[s][e]!=-1){
            return dp[s][e];
        }
        
        if(bari){
            int shuruse =  piles[s] + helper(piles,dp,!bari,s+1,e) ;
            int lastse = piles[e]+helper(piles,dp,!bari , s ,e-1);
            dp[s][e] = max(shuruse,lastse);
        }
        else{
            int shuruse =  -piles[s] + helper(piles,dp,!bari,s+1,e) ;
            int lastse = -piles[e]+helper(piles,dp,!bari , s ,e-1);
            dp[s][e] = max(shuruse,lastse);
        }
        return dp[s][e];
        
    }
    
    bool stoneGame(vector<int>& piles) {
       int n=piles.size();
        
        vector<vector<int>>dp(n , vector<int>(n,-1));
        
        return helper(piles,dp,1,0,n-1)>0;
        
    }
};