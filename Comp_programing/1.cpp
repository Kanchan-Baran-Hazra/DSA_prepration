#include <bits/stdc++.h>
using namespace std;

int helper(int n,vector<int>& dp){
    if(n<=2) return n;
    if(dp[n]!=-1) return dp[n];
    return dp[n]= helper(n-1,dp)+helper(n-2,dp);
}

int climbing_stair(){
    int n=3;
    vector<int> dp(n+1,-1);
    return helper(n,dp);
}

int main(){
    cout<< climbing_stair();
    return 0;
}