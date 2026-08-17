class Solution {
public:
    static long long helper(int n){
        if(n==1) return 1;
        if (n % 3 != 0) return 0;

        return (long long)3*helper(n/3);
    }
    bool isPowerOfThree(int n) {
        if(n<=0) return false;
        
        return n==helper(n);
    }
};