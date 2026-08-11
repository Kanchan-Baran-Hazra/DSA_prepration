class Solution {
public:
    int missingInteger(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }

        int pres=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[i-1]+1) break;
            pres+=nums[i];
        }

        for(int i=pres;i<INT_MAX;i++){
            if(mp.find(i)==mp.end()) return i;
        }

        return -1;
    }
};