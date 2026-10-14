#include <bits/stdc++.h>
using namespace std;


int climb_stair2(){
    vector<int> cost={1,100,1,3,2};
    int n=cost.size();
    vector<int> dp(n+1);

    dp[0]=0;
    dp[1]=0;

    for(int i=2;i<=n;i++){
        dp[i]=min(dp[i-1]+cost[i-1],dp[i-2]+cost[i-2]);
    }

    return dp[n];
}

int main(){
    // cout<<"hello"<<endl;
    cout<<climb_stair2();
    return 0;
}