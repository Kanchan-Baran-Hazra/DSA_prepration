class Solution {
public:
    static double helper(double x,long n){
        if(n==0) return 1;
        if(n<0) return helper(1/x,-n);
        if(n%2==0) return helper(x*x,n/2);
        else return x*helper(x*x,(n-1)/2);
    }
    double myPow(double x, int n) {
        // long double ans=1;
        return helper(x,(long)n);
    }
};