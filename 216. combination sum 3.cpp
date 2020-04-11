class Solution {
public:
    vector<vector<int>> ans;
    
    void helper( int k ,int n , vector<int>& v,int ind ){
        if(n<0){
            return;
        }
        
        if(k==0 && n==0){
            ans.push_back(v);
            return;
        }
        
        for( int i=ind;i<=9;i++ ){
         v.push_back(i);
            helper(k-1 , n-i ,v,i+1);
         v.pop_back();       
        }
        
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>v;
        helper(k,n,v,1);
        return ans;
    }
};