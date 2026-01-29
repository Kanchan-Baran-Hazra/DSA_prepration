class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int large=-1;
        int large2=-1;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>large){
                large2=large;
                large=arr[i];
            }else if(arr[i]>large2 && arr[i]<large){
                large2=arr[i];
            }
        }
        return large2;
    }
};