class Solution {
  public:
    int posSubarray(vector<int> &arr,int maxi){
        int count=0; int sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            if(sum>maxi){
                count++;
                sum=arr[i];
            }
        }
        count++;
        return count;
    }
    int splitArray(vector<int>& arr, int k) {
        // code here
        int ans=INT_MAX;
        int low=0;
        int high=0;
        for(int i=0;i<arr.size();i++){
            low=max(low,arr[i]);
            high+=arr[i];
        }
        
        while(low<=high){
            int mid=low+(high-low)/2;  //hiest sum
            int num=posSubarray(arr,mid);
            if(num<=k){
                high=mid-1;
                ans=mid;
            }
            else low=mid+1;
        }
    }
};