class Solution {
  public:
    vector<int> prefSum(vector<int> &arr) {
        // code here
        for(int i=1;i<arr.size();i++){
            arr[i]+=arr[i-1];
        }
        return arr;
    }
};