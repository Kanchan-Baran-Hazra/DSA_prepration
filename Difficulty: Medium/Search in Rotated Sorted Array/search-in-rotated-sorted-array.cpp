class Solution {
  public:
    int search(vector<int>& arr, int key) {
        // Code Here
        if(arr[arr.size()-1]==key) return arr.size()-1;
        if(arr[0]==key) return 0;
        int i=0;
        int j=arr.size()-1;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(arr[mid]==key) return mid;
            else if(arr[mid]>=arr[i]){
                if(arr[mid]>key && arr[i]<=key) j=mid-1;
                else i=mid+1;
            }
            else if(arr[mid]<=arr[j]){
                if(arr[mid]<key && arr[j]>=key) i=mid+1;
                else j=mid-1;
            }
        }
        return -1;
    }
};