#include <bits/stdc++.h>
using namespace std;

int helper(int i,int prev,vector<int>& nums){
    if(i>=nums.size()) return 0;
    if(prev==-1 || nums[i]%prev==0){
        return max(helper(i+1,prev,nums),1+helper(i+1,nums[i],nums));
    }
    return helper(i+1,prev,nums);
}

int long_divisable_subset(vector<int>& nums){
    int n=nums.size();
    sort(nums.begin(),nums.end());
    return helper(0,-1,nums);
}

int main(){
    // cout<<"helllo"<<endl;
    vector<int> nums={1,7,14,21,28,42,49,63,56};
    cout<<long_divisable_subset(nums);
    return 0;
}