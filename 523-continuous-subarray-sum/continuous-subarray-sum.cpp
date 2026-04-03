class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int sum=0;
        mp[sum]=0;

        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int remain=sum%k;
            if(mp.find(remain)!=mp.end()){
                if((i+1)-mp[remain]>=2)
                  return true;
                else continue;
            }
            mp[remain]=i+1;
        }

        return false;
    }
};