// climbing stairs problem

#include <bits/stdc++.h>
using namespace std;


int count_stair(int n,vector<int>& dp){
    if(n<=2) return n;

    if(dp[n]!=-1) return dp[n];

    return dp[n]= count_stair(n-1,dp)+count_stair(n-2,dp);
}

int grid_cs(int n){
    vector<int> dp(n+1,-1);

    dp[0]=0;
    dp[1]=1;
    dp[2]=2;

    for(int i=3;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}

int main(){
    // cout<<"hello";
    int n=3;
    vector<int> dp(n+1,-1);
    cout<<count_stair(n,dp)<<"\n";
    // cout<<grid_cs(n);
    return 0;
}