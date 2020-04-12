class Solution {
public:
    
void helper(vector<int>& candidates,int target,vector<vector<int>>& ans,vector<int>& v,int sum,int ind ){
    if(sum==target){
        ans.push_back(v);
        return;
    }    
     if(sum>target){
         return;
     }   
    
    for(;ind<candidates.size();ind++){
       sum+= candidates[ind];
        v.push_back(candidates[ind]);
          helper(candidates,target,ans,v,sum,ind);
        sum-= candidates[ind];
        v.pop_back();
     }
        return;
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > ans;
        vector<int> v;
        helper(candidates,target,ans,v, 0,0 );
        
        return ans;
    }
};