/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        
        vector<int>v = binaryMatrix.dimensions();
        int n = v[0];
        int m=  v[1];
        int ans=10000;
        for(int i=0;i<n;i++){
            int temp=-1;
            int s=0,e=m-1;
            while(s<=e){
                if(s==e){
                   binaryMatrix.get(i,s) ==1 ? temp = s :-1;
                    break;
                }
                int mid = (s+e)/2;
                
                if(binaryMatrix.get(i,mid) ==0){
                    s=mid+1;
                }
                else{
                    e=mid;
                }
            }
            if(temp!=-1){
                ans = min(ans,temp);
            }
        }
        if(ans==10000)ans=-1;
        return ans;
    }
};