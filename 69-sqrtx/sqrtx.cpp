class Solution {
public:
    int mySqrt(int x) {
        int ans=0;
        int i=0;
        int j=x;

        while(i<=j){
            int mid=i+(j-i)/2;

            if((long long)mid*mid==x) return mid;
            else if((long long)mid*mid<x){
                ans=mid;
                i=mid+1;
            }else j=mid-1;
        }
        return ans;
    }
};