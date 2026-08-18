class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int i=0;
        int j=0;
        for(j;j<k;j++){
            mp[nums[j]]++;
        }
        int n=nums.size();
        if(k==n){
            sort(nums.begin(),nums.end());
            return max(nums[0],nums[n-1]);
        }
        i++;
        while(j<n){
            for(int k=i;k<=j;k++){
                mp[nums[k]]++;
            }

            i++;
            j++;
        }

        int ans=-1;
        for(auto x:mp){
            if(x.second==1){
                ans=max(ans,x.first);
            }
        }

        return ans;
    }
};