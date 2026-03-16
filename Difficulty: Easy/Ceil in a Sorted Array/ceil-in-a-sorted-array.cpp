// User function Template for C++
class Solution {
  public:
    int findCeil(vector<int>& arr, int x) {
        // code here
        int i=0;
        int j=arr.size()-1;
        int ans=-1;
        
        while(i<=j){
            int mid=i+(j-i)/2;
            
            if(arr[mid]>=x){
                ans=mid;
                j=mid-1;
            }else{
                i=mid+1;
            }
        }
        return ans;
    }
};