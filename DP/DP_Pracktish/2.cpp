// frog jump problem

#include <bits/stdc++.h>
using namespace std;

int helper(int i,vector<int>& path,vector<int>& dp){
    if(i+1>=path.size()) return 0;

    if(dp[i]!=-1) return dp[i];


    int f_stp=helper(i+1,path,dp)+abs(path[i]-path[i+1]);
    int s_stp=INT_MAX;
    if(i+2<path.size())
    s_stp=helper(i+2,path,dp)+abs(path[i]-path[i+2]);

    return dp[i]= min(f_stp,s_stp);
}

int frog_jump(){
    vector<int> dp(5,-1);
    vector<int> path={10,20,30,10};
    return helper(0,path,dp);
}


int main(){
    cout<<frog_jump();
    return 0;
}