class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>ans(2,-1);
        unordered_map<int,int>mp;

        for(int i=0;i<n;i++){
            if(mp.find(nums[i])!=mp.end()){
                ans[0]=nums[i];
                break;
            }
            mp[nums[i]]++;
        }

        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        sum-=ans[0];
        int actual_sum=(n*(n+1))/2;
        ans[1]=actual_sum-sum;

        return ans;
    }
};