class Solution {
    int helper(int i,int j,string &s1,string &s2,vector<vector<int>>& dp){
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        if(s1[i]==s2[j]) return dp[i][j]= 1+helper(i-1,j-1,s1,s2,dp);

        return dp[i][j]= max(helper(i-1,j,s1,s2,dp),helper(i,j-1,s1,s2,dp));
    }
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        string reversed(s.rbegin(), s.rend());
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return helper(n-1,n-1,s,reversed,dp);
    }
public:
    int minInsertions(string s) {
        return s.size()-longestPalindromeSubseq(s);
    }
};