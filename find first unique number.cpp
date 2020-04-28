class FirstUnique {
public:
    unordered_map<int,int>mp;
    list<int> lst;
    
    FirstUnique(vector<int>& nums) {
          for(auto a : nums){
            mp[a]++;
              lst.push_back(a);
          }
        
    }
    
    void rem(list<int> &lst , int val){
        lst.remove(val);
    }
    
    int showFirstUnique() {
       while(lst.size()>0){
           if(mp[lst.front()]>1){
               lst.pop_front();
           }else{
               return lst.front();
           }
       }
        return -1;
    }
    
    void add(int a) {
         mp[a]++;
              lst.push_back(a);
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */