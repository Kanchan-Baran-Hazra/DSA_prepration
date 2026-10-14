#include <bits/stdc++.h>
using namespace std;


// Memoization dp
int helper(int n,vector<int>& dp){
    if(n<=3) return n;
    if(dp[n]!=-1) return dp[n];

    return dp[n]=helper(n-1,dp)+helper(n-2,dp);
}

int climb_str(){
    int n=6;
    vector<int> dp(n+1,-1);
    return helper(n,dp);
}


// Tabular dp
int climb_str1(){
    int n=6;
    vector<int> dp(n+1);
    dp[1]=1;
    dp[2]=2;

    for(int i=3;i<=n;i++){
        dp[i]= dp[i-1]+ dp[i-2];
    }

    return dp[n];
}

int main(){
    // cout<<"hello"<<endl;
    cout<<climb_str1()<<endl<<climb_str()<<endl;
    return 0;
}