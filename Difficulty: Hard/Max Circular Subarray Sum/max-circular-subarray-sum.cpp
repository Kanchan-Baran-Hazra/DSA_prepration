class Solution {
  public:
    int maxCircularSum(vector<int> &arr) {
        // code here
        int max_sum_sub=INT_MIN;
        int max_sum=0;
        int min_sub_sum=INT_MAX;
        int min_sum=0;
        int sum=0;
        
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            max_sum+=arr[i];
            max_sum_sub=max(max_sum_sub,max_sum);
            if(max_sum<0){
                max_sum=0;
            }
            
            min_sum+=arr[i];
            min_sub_sum=min(min_sub_sum,min_sum);
            if(min_sum>0){
                min_sum=0;
            }
        }
        
        return (sum==min_sub_sum)? max_sum_sub:max(max_sum_sub,sum-min_sub_sum);
    }
};