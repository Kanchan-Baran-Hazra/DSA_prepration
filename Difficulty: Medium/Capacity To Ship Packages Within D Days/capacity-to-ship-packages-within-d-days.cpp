// User function Template for C++

class Solution {
  public:
    int minDayreq(int arr[],int maxi,int n){
        int count=0;int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum>maxi){
                count++;
                sum=arr[i];
            }
        }
        return ++count;
    }
    int leastWeightCapacity(int arr[], int n, int d) {
        // code here
        int ans=0;
        int l=1;
        int r=0;
        for(int i=0;i<n;i++){
            r+=arr[i];
            l=max(l,arr[i]);
        }
        
        while(l<=r){
            int mid=l+(r-l)/2;
            int days=minDayreq(arr,mid,n);
            if(days<=d){
                ans=mid;
                r=mid-1;
            }else l=mid+1;
        }
    }
};