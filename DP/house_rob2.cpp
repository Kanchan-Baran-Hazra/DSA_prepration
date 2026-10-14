#include <bits/stdc++.h>
using namespace std;


// Tabulation dp
int helper(int st,int en,vector<int>& house, vector<int>& dp){
    for(int i=st+2;i<=en;i++){
        dp[i]=max(house[i]+dp[i-2],dp[i-1]);
    }
    return dp[en];
}

int house_rob2(){
    vector<int> house={2,7,9,3,2};
    // vector<int> house={30,20,50,10,40};
    int n=house.size();
    vector<int> dp(n+1);
    dp[0]=house[0];
    dp[1]=max(house[1],house[0]);
    int first= helper(0,n-2,house,dp);
    cout<<first<<endl;
    dp[2]=max(dp[1],house[2]);
    int second=helper(1,n-1,house,dp);
    cout<<second<<endl;
    return max(first,second);
}


int main(){
    // cout<<"hello"<<endl;
    cout<<house_rob2();
    return 0;
}