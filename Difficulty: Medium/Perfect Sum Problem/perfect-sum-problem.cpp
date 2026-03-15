class Solution {
  public:
    int helper(vector<int>& arr, int target,int n,vector<vector<int>> &t){
        if(n < 0){
            if(target == 0) return 1;
            return 0;
        }
        if(t[n][target]!=-1) return t[n][target];
        if(target>=arr[n])
            return t[n][target]=helper(arr,target-arr[n],n-1,t)+helper(arr,target,n-1,t);
        else{
            return t[n][target]=helper(arr,target,n-1,t);
        }
    }
    int perfectSum(vector<int>& arr, int target) {
        // code here
        vector<vector<int>>t(arr.size(),vector<int>(target+1,-1));
        return helper(arr,target,arr.size()-1,t);
    }
};