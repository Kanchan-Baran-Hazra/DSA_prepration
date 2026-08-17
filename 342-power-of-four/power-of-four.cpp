class Solution {
public:
    static long long helper(int n){
        if(n==1) return 1;
        if (n % 4 != 0) return 0;

        return (long long)4*helper(n/4);
    }
    bool isPowerOfFour(int n) {
        if(n<=0) return false;
        
        return n==helper(n);
    }
};