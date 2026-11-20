#include <bits/stdc++.h>
using namespace std;

int helper(int i,vector<int>& path,vector<int>& dp){
    if(i+1>=path.size()) return 0;

    if(dp[i]!=-1) return dp[i];

    int take1=abs(path[i]-path[i+1])+helper(i+1,path,dp);
    int take2=INT_MAX;
    if(i+2<path.size())
    take2=abs(path[i]-path[i+2])+helper(i+2,path,dp);

    return dp[i]= min(take1,take2);
}

int frog_jump(){
    vector<int> path={10,20,30,10};
    int n=path.size();
    vector<int> dp(n,-1);
    return helper(0,path,dp);
}

int main(){
    cout<< frog_jump();
    return 0;
}