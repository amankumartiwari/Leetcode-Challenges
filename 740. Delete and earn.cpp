class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
     
        vector<int>count(10003,0);
        for(auto i:nums){
            count[i]++;
        }
        vector<int>dp(10003,0);
        dp[1] = count[1];
        int ans=dp[1];
        for(int i=2;i<=10000;i++){
            dp[i] = max(dp[i-1] , dp[i-2] + i*count[i] );
          ans= max(ans,dp[i]);
        }
        return ans;
    }
};