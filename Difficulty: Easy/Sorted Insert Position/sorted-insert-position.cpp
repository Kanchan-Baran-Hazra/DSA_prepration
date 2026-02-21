class Solution {
  public:
    int searchInsertK(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        if(k>arr[n-1]) return n;
        if(k<arr[0]) return 0;
        
        int i=0;
        int j=n-1;
        while(i<=j){
            int mid=i+(j-i)/2;
            
            if(arr[mid]==k) return mid;
            else if(arr[mid]<k){
                i=mid+1;
            }else{
                j=mid-1;
            }
        }
        return i;
    }
};