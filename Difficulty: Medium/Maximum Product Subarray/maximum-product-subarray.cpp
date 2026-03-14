class Solution {
  public:
    int maxProduct(vector<int> &arr) {
        // code here
        int n=arr.size()-1;
        int left=1;
        int right=1;
        int maxi=INT_MIN;
        for(int i=0;i<arr.size();i++){
            left=left*arr[i];
            right=right*arr[n-i];
            maxi=max(maxi,max(left,right));
            right=(right==0)? 1:right;
            left=(left==0)? 1:left;
        }
        return maxi;
    }
};