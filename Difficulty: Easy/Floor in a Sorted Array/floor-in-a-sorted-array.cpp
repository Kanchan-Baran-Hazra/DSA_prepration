class Solution {
  public:
    int findFloor(vector<int>& arr, int x) {
        // code here
        int i=0;
        int j=arr.size()-1;
        int ans=-1;
        
        while(i<=j){
            int mid=i+(j-i)/2;
            
            if(arr[mid]<=x){
                ans=mid;
                i=mid+1;
            }else{
                j=mid-1;
            }
        }
        
        return ans;
    }
};
