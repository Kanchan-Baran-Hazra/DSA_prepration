class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        int i=0;
        int j=0;
        int sum=0;
        for(j=0;j<k;j++){
            sum+=arr[j];
        }
        int ans=sum;
        while(j<arr.size()){
            sum+=arr[j];
            sum-=arr[i];
            ans=max(ans,sum);
            j++;
            i++;
        }
        return ans;
    }
};