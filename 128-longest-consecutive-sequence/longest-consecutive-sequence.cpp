class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        sort(nums.begin(),nums.end());
        unordered_map<int,int>mp;
        int ans=1;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto x:mp){
            int current=x.first;
            int count=1;
            if(mp.find(current-1)!=mp.end()) continue;
            while(mp.find(current+1)!=mp.end()){
                count++;
                current+=1;
            }
            ans=max(ans,count);
        }
        return ans;
    }
};