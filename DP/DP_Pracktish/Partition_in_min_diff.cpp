#include<bits/stdc++.h>
using namespace std;


bool helper(vector<int>& nums,int k,int i,vector<vector<int>>& dp){
    if(k==0) return true;
    if(i==0) return nums[0]==k;
    if(dp[i][k]!=-1) return dp[i][k];

    bool not_take=helper(nums,k,i-1,dp);
    bool take=false;
    if(nums[i]<=k) take=helper(nums,k-nums[i],i-1,dp);

    return dp[i][k]= take || not_take;
}

bool tabu_subsumTarget(vector<int>& nums,int k){
    int n=nums.size();
    vector<vector<bool>> dp(n,vector<bool>(k+1,false));

    for(int i=0;i<n;i++){
        dp[i][0]=true;
    }

    dp[0][nums[0]]=true;

    for(int i=1;i<n;i++){
        for(int j=1;j<=k;j++){
            bool not_take=dp[i-1][j];
            bool take=false;
            if(nums[i]<=j) take=dp[i-1][j-nums[i]];
        
            dp[i][j]= take || not_take;
        }
    }

    return dp[n-1][k];
}

bool subsumTarget(vector<int>& nums,int k){
    int n=nums.size();
    vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
    // return helper(nums,k,n-1,dp);
    return tabu_subsumTarget(nums,k);
}

vector<vector<bool>> tabu_subsumTarget1(vector<int>& nums,int k){
    int n=nums.size();
    vector<vector<bool>> dp(n,vector<bool>(k+1,false));

    for(int i=0;i<n;i++){
        dp[i][0]=true;
    }

    dp[0][nums[0]]=true;

    for(int i=1;i<n;i++){
        for(int j=1;j<=k;j++){
            bool not_take=dp[i-1][j];
            bool take=false;
            if(nums[i]<=j) take=dp[i-1][j-nums[i]];
        
            dp[i][j]= take || not_take;
        }
    }

    return dp;
}


int minSubDiff(vector<int>& nums){
    int n=nums.size();
    int total=0;
    for(int i=0;i<nums.size();i++){
        total+=nums[i];
    }
    vector<vector<bool>> dp= tabu_subsumTarget1(nums,total);

    int mini=INT_MAX;

    for(int i=0;i<=total;i++){
        if(dp[n-1][i]){
            int s1=i;
            int s2=total-i;

            mini=min(mini,abs(s1-s2));
        }
    }

    return mini;
}

int main(){
    // cout<<"hello";
    vector<int> nums={1,3,7,5};
    if(subsumTarget(nums,14)) cout<<"Possible";
    else cout<<"Not possible!";

    // cout<<minSubDiff(nums);
    return 0;
}