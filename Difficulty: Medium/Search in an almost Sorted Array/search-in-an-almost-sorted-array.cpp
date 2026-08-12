class Solution {
  public:
    int findTarget(vector<int>& arr, int target) {
        // code here
        // sort(arr.begin(),arr.end());
        int i=0;
        int j=arr.size()-1;
        while(i<=j){
            int mid=i+(j-i)/2;
            
            if(arr[mid]==target) return mid;
            else if(arr[mid-1]==target) return mid-1;
            else if(arr[mid+1]==target) return mid+1;
            else if(arr[mid]>target) j=mid-1;
            else i=mid+1;
        }
        return -1;
    }
};