class Solution {
public:
    int helper(int n,vector<int> &t){
        if(n<0) return 0;
        if(n==0) return 1;
        if(t[n]!=-1) return t[n];
        int l=helper(n-1,t);
        int r=helper(n-2,t);
        t[n]=l+r;
        return l+r;
    }
    int climbStairs(int n) {
        int count=0;
        vector<int>t(50,-1);
        return helper(n,t);
    }
};