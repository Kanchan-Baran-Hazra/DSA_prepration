#include <bits/stdc++.h>
using namespace std;


// Memoization dp
// int helper(int i,vector<int>& cost,vector<int>& dp){
//     if(i+1>=cost.size()) return 0;
//     // if(dp[i]!=-1) return dp[i];

//     int step1=abs(cost[i]-cost[i+1])+helper(i+1,cost,dp);
//     int step2=abs(cost[i]-cost[i+2])+helper(i+2,cost,dp);
//     // cout<<step1<<endl<<step2<<endl;
//     return dp[i]=min(step1,step2);
// }

// int frogJump_cost(){
    // vector<int> cost={30,20,50,10,40};
    // int n=cost.size();
    // vector<int> dp(n+1,-1);
//     return helper(0,cost,dp);
// }

int frogJump_cost(){
    vector<int> cost={30,20,50,10,40};
    int n=cost.size();
    vector<int> dp(n+1);

    dp[0]=0;
    dp[1]=abs(dp[1]-dp[0]);

    for(int i=2;i<n;i++){
        int fst=dp[i-2]+abs(cost[i-2]-cost[i]);
        int sec=dp[i-1]+abs(cost[i-1]-cost[i]);
        dp[i]=min(fst,sec);
    }

    return dp[n-1];
}

int main(){
    cout<<frogJump_cost();
    // cout<<abs(3-2);
    return 0;
}


