class Solution {
public:
    static bool isposs(int mid,int n){
        if(((long long)mid*(mid+1))/2<=n) return true;
        return false;
    }
    int arrangeCoins(int n) {
        int i=1;
        int j=(n/2)+1;

        while(i<=j){
            int mid=i+(j-i)/2;

            if(isposs(mid,n)){
                i=mid+1;
            }else j=mid-1;
        }
        return j;
    }
};