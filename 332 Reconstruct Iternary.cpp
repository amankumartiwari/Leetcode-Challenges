class Solution {
public:
    vector<string> ans;
    unordered_map<string , vector<string>> mp ; 
    
    void dfs(string src){
        
        while(mp[src].size()){
            
            string dest =  *mp[src].begin();
           mp[src].erase(mp[src].begin());
            dfs(dest);
        }
        ans.push_back(src);
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        
        for( auto aa: tickets ){
            string src = aa[0],dest = aa[1];
            mp[src].push_back(dest);
        }
      
        for(auto i:mp){
            sort( mp[i.first].begin() , mp[i.first].end() );
        }
                dfs("JFK");
     
        return vector<string>( ans.rbegin() , ans.rend() );
    }
};