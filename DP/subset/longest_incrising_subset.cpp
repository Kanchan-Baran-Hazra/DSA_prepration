#include <bits/stdc++.h>
using namespace std;

int helper(int i,int prev,vector<int>& nums,vector<vector<int>>& dp){
    if(i>=nums.size()) return 0;
    
    if(prev!=-1 && dp[i][prev]!=-1) return dp[i][prev];

    if(prev==-1 || nums[i]>prev){
        return dp[i][prev]= max(helper(i+1,prev,nums,dp),1+helper(i+1,nums[i],nums,dp));
    }

    return dp[i][prev]= helper(i+1,prev,nums,dp);
}

int long_subset(vector<int>& nums){
    int n=nums.size();
    int maxi=0;
    for(int i=0;i<n;i++){
        maxi=max(maxi,nums[i]);
    }
    vector<vector<int>> dp(n+1,vector<int>(maxi+1,-1));
    return helper(0,-1,nums,dp);
}

int main(){
    // cout<<"helllo"<<endl;
    vector<int> nums={10,9,2,5,3,7,101,18};
    cout<<long_subset(nums);
    return 0;
}