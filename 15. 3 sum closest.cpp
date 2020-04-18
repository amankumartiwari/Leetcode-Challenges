class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector< vector<int> >ans;
        
        unordered_map <int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        
        for(int i=0;i<nums.size();i++){
              mp[nums[i]]--;
            for(int j=i+1;j<nums.size();j++){
                mp[nums[j]]--;
                if(mp[nums[j]]<0)
                    continue;
                int val = 0-(nums[i]+nums[j]);
                if(mp.count(val)==1 && mp[val]>0 ){
                   mp[val]--; 
                    vector<int> v;
                    v.push_back(nums[i]);
                    v.push_back(nums[j]);
                    v.push_back(val);
                    ans.push_back(v);
                }
                
            }
        }
        
        return ans;
    }
};