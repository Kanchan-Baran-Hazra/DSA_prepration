class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,pair<int,pair<int,int>>> mp;
        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i])!=mp.end()){
                mp[nums[i]].second.first=i;
                mp[nums[i]].second.second++;
            }else{
                mp[nums[i]].first=i;
                mp[nums[i]].second.first=i;
                mp[nums[i]].second.second=1;
            }
        }
        int maxi=0;
        int l=0;
        int r=0;
        for(auto x:mp){
            if(x.second.second.second>maxi){
                maxi=x.second.second.second;
                l=x.second.first;
                r=x.second.second.first;
            }else if(x.second.second.second==maxi){
                int p=x.second.second.first-x.second.first;
                if(p<r-l){
                    maxi=x.second.second.second;
                    l=x.second.first;
                    r=x.second.second.first;
                }
            }else{
                continue;
            }
        }

        return r-l+1;
    }
};