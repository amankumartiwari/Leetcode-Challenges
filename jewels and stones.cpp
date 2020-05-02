class Solution {
public:
    int numJewelsInStones(string J, string S) {
       
        map<char,int>mp;
        for(char c:S){
            mp[c]++;
        }
        int ans=0;
        for(char c:J){
            if(mp.count(c)==1){
                ans+=mp[c];
            }
        }
        return ans;
    }
};