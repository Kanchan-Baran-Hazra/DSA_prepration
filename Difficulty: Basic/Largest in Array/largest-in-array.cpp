class Solution {
  public:
    int largest(vector<int> &arr) {
        // code here
        int large=arr[0];
        if(arr.size()==1)
        return arr[0];
        for(int i=0;i<arr.size();i++){
            if(arr[i]>large)
            large=arr[i];
        }
        return large;
    }
};
