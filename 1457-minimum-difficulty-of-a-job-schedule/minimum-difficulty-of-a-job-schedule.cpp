#include<bits/stdc++.h>

class Solution {
    int helper(vector<int>& job,int n,int d,int i,vector<vector<int>>& dp){
        if(d==1){
            return *max_element(job.begin()+i,job.end());
        }
        if(dp[i][d]!=-1) return dp[i][d];

        int ans=INT_MAX;
        int maxi=INT_MIN;
        for(int j=i;j<=job.size()-d;j++){
            maxi=max(maxi,job[j]);
            int res=maxi+helper(job,n,d-1,j+1,dp);

            ans=min(ans,res);
        }

        return dp[i][d]= ans;
    }
public:
    int minDifficulty(vector<int>& job, int d) {
        int n=job.size();
        if(n<d) return -1;
        vector<vector<int>> dp(n+1,vector<int>(d+1,-1));
        return helper(job,n,d,0,dp);
    }
};