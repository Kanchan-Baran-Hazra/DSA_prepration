class Solution {
  public:
    int helper(vector<int> &arr,int n,vector<int> &t){
        if(n>=arr.size()) return 0;
        if(t[n]!=-1) return t[n];
        return t[n]=max(helper(arr,n+2,t)+arr[n],helper(arr,n+1,t));
    }
    int findMaxSum(vector<int>& arr) {
        // code here
        vector<int>t(arr.size(),-1);
        return helper(arr,0,t);
    }
};