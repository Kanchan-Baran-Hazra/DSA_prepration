class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int ans=0;
        int sum=0;
        int remain=0;
        mp[sum]=1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            remain=sum-k;
            if(mp.find(remain)!=mp.end()){
                ans+=mp[remain];
            }
            mp[sum]++;
        }
        return ans;
    }
};