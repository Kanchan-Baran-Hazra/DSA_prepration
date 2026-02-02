class Solution {
  public:
    int lowerBound(vector<int>& arr, int target) {
        // code here
        int i=0;
        int j=arr.size()-1;
        int ans=j+1;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(arr[mid]>=target){
                ans=mid;
                j=mid-1;
            }else i=mid+1;
        }
        return ans;
    }
};
