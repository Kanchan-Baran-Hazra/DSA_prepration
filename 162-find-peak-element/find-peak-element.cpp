class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        if(arr.size()==1) return 0;
        if(arr[0]>arr[1]) return 0;
        if(arr[arr.size()-1]>arr[arr.size()-2]) return arr.size()-1;
        int i=1;
        int j=arr.size()-2;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]) return mid;
            else if(arr[mid]>arr[mid-1] && arr[mid]<arr[mid+1]) i=mid+1;
            else j=mid-1;
        }
        return -1;
    }
};