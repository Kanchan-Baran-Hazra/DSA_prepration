class Solution {
  public:
    int findMin(vector<int>& arr) {
        // code here
        int i=0;
        int j=arr.size()-1;
        int ans=INT_MAX;
        
        while(i<=j){
            int mid=i+(j-i)/2;
            
            if(arr[mid]<=arr[j]){
                ans=min(ans,arr[mid]);
                j=mid-1;
            }else{
                ans=min(ans,arr[i]);
                i=mid+1;
            }
        }
        return ans;
    }
};