class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        if(nums.size()==0)
            return -1;
        
        int l=0,r=nums.size()-1;
        while(l<=r){
            int mid= (r+l)/2;
            
            if(nums[mid]==target){
                return mid;
            }
            
            //for left half sorted
            if( nums[l]<=nums[mid] ){
                if(nums[l]<=target && nums[mid]>=target){
                    r=mid-1;
                    continue;
                }else{
                    l=mid+1;
                    continue;
                }
            }
            //for right half
            else{
                if(nums[mid+1]<=target && nums[r]>=target ){
                    l=mid+1;
                    continue;
                }else{
                    r=mid-1;
                    continue;
                }
                    
            }
            
            
        }
        return -1;
    }
};