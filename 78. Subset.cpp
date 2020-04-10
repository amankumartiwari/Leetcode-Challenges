class Solution {
public:
    
    void helper(vector<int>& nums, vector<vector<int>>& ans,int ind,int n,vector<int>& v,int k  ){
        if(v.size() == k){
            ans.push_back(v);
            return ;
        }
        //vector<int> v ;
        for(int i=ind ; i<n;i++){
            v.push_back(nums[i]);
            helper(nums , ans , i+1 , n, v,k);
            v.pop_back();
        }
        
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        int n  =nums.size();
        vector<vector<int>> ans;
        vector<int> v;
        for(int k=0;k<=n;k++)
         helper(nums , ans , 0 , n ,v,k);
        
        return ans;
    }
};