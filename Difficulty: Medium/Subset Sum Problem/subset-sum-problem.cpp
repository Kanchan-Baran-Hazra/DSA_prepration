class Solution {
  public:
    bool helper(vector<int>& arr, int sum,int i,vector<vector<int>> &t){
        if(sum==0) return true;
        if(i>=arr.size() && sum!=0) return false;
        if(t[sum][i]!=-1) return (t[sum][i]==1)? true:false;
        
        if(arr[i]<=sum){
            bool take=helper(arr,sum-arr[i],i+1,t);
            t[sum][i]=(take==true)? 1:0;
            bool not_take=t[sum][i]=helper(arr,sum,i+1,t);
            t[sum][i]=(not_take==true)? 1:0;
            return take || not_take;
        }
        bool not_take=t[sum][i]=helper(arr,sum,i+1,t);
        t[sum][i]=(not_take==true)? 1:0;
        
        return not_take;
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        vector<vector<int>>t(sum+1,vector<int>(arr.size(),-1));
        return helper(arr,sum,0,t);
    }
};