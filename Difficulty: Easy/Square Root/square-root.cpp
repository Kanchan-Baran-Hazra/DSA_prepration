class Solution {
  public:
    int floorSqrt(int n) {
        // code here
        int ans=n;
        int i=0;
        int j=n;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(mid*mid==n) return mid;
            else if(mid*mid<n){
                ans=mid;
                i=mid+1;
            }else j=mid-1;
        }
        return ans;
    }
};