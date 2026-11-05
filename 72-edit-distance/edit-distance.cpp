class Solution {
    int helper(int i,int j,string s1,string s2,vector<vector<int>>& dp){
        if(j<0) return i+1;
        if(i<0) return j+1;

        if(dp[i][j]!=-1) return dp[i][j];

        if(s1[i]==s2[j]) return dp[i][j]= helper(i-1,j-1,s1,s2,dp);
        
        int inst=helper(i-1,j,s1,s2,dp)+1;
        int del=helper(i,j-1,s1,s2,dp)+1;
        int rep=helper(i-1,j-1,s1,s2,dp)+1;

        return dp[i][j]= min(inst,min(del,rep));
    }
public:
    int minDistance(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return helper(n-1,m-1,s1,s2,dp);
    }
};