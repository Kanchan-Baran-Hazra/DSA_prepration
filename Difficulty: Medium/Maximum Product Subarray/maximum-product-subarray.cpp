class Solution {
  public:
    int maxProduct(vector<int> &arr) {
        // code here
        int ans=INT_MIN;
        int n=arr.size();
        int prod=1;
        int prod1=1;
        for(int i=0;i<arr.size();i++){
            prod*=arr[i];
            prod1*=arr[n-1-i];
            ans=max(ans,max(prod,prod1));
            if(prod==0) prod=1;
            if(prod1==0) prod1=1;
        }
        return ans;
    }
};