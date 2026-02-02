class Solution {
  public:
    int binarysearch(vector<int> &arr, int k) {
        // code here
        if(arr[arr.size()-1]<k || arr[0]> k) return -1;
        int i=0;
        int j=arr.size()-1;
        while(i<=j){
            int mid=(i+j)/2;
            if(arr[mid]==k){
                while(arr[mid-1]==k) mid--;
                return mid;
            }
            else if(arr[mid]<k) i=mid+1;
            else j=mid-1;
        }
        return -1;
    }
};