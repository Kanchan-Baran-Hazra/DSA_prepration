#include <bits/stdc++.h>
using namespace std;


// Memoization dp
// int helper(int i,vector<int>& house,vector<int>& dp){
//     if(i>=house.size()) return 0;
//     if(dp[i]!=-1) return dp[i];

//     int take=house[i]+helper(i+2,house,dp);
//     int not_take=helper(i+1,house,dp);

//     return dp[i]=max(take,not_take);
// }

// int house_rob(){
//     vector<int> house={2,7,9,3,1};
//     vector<int> dp(house.size()+1,-1);
//     return helper(0,house,dp);
// }

int house_rob(){
    vector<int> house={2,7,9,3,1};
    vector<int> dp(house.size());
    dp[0]=house[0];
    dp[1]=max(house[1],house[0]);

    for(int i=2;i<house.size();i++){
        dp[i]=max(house[i]+dp[i-2],dp[i-1]);
    }

    return dp[house.size()-1];
}

int main(){
    cout<<house_rob();
    return 0;
}