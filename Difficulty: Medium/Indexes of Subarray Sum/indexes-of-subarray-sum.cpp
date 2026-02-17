class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        // code here
        int i=0;
        int j=0;
        int sum=0;
        vector<int>ans;
        while(j<arr.size()){
            sum+=arr[j];
            
            while(sum>target){
                sum-=arr[i];
                i++;
            }
            if(sum==target){
                ans.push_back(i+1);
                ans.push_back(j+1);
                return ans;
            }
            j++;
        }
        
        ans.push_back(-1);
        return ans;
    }
};