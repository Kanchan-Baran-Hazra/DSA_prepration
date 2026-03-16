class Solution {
  public:
    int requiredHour(vector<int> &arr,int maxi){
        int count=0;
        for(int i=0;i<arr.size();i++){
            int sum=0;
            count+=ceil((double)arr[i]/maxi);
        }
        return count;
    }
    int kokoEat(vector<int>& arr, int k) {
        int l=1;
        int r=INT_MIN;
        for(int i=0;i<arr.size();i++){
            r=max(r,arr[i]);
        }
        int ans;
        while(l<=r){
            int mid=l+(r-l)/2;
            int num=requiredHour(arr,mid);
            if(num<=k){
                ans=mid;
                r=mid-1;
            }else l=mid+1;
        }
        return ans;
    }
};