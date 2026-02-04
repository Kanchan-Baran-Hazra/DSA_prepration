class Solution {
  public:
    void helper(int n,int &ans){
        if(n==0) return;
        int dig=n%10;
        ans+=dig;
        helper(n/10,ans);
    }
    
    int sumOfDigits(int n) {
        // code here
        int ans=0;
        helper(n,ans);
        return ans;
    }
};