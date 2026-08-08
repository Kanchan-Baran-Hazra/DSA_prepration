class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        priority_queue<pair<int,int>>pq;
        for(auto x:mp){
            pq.push({x.second,x.first});
        }
        vector<int>ans;
        int count=0;
        while(pq.size()!=0 && count<2){
            pair<int,int>p=pq.top();
            pq.pop();
            if(p.first>n/3){
                ans.push_back(p.second);
                count++;
            }else break;
        }

        return ans;
    }
};