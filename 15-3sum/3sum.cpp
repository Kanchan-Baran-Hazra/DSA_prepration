class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int j=nums.size()-1;
            int k=i+1;
            // while(k<nums.size() && nums[i]==nums[k]) k++;
            // while(j>k && nums[i]==nums[j] || nums[j]==nums[k]) j--;
            while(k<j){
                vector<int>sub;
                if(nums[i]+nums[j]+nums[k]==0){
                    sub.push_back(nums[i]);
                    sub.push_back(nums[k]);
                    sub.push_back(nums[j]);
                    ans.push_back(sub);
                    k++;
                    j--;
                    while(k<nums.size() && nums[k]==nums[k-1]) k++;
                    while(j>k && nums[j]==nums[j+1]) j--;
                }else if(nums[i]+nums[j]+nums[k]>0){
                    j--;
                    while(j>k && nums[j]==nums[j+1]) j--;
                }else{
                    k++;
                    while(k<nums.size() && nums[k]==nums[k-1]) k++;
                }
            }
        }
        return ans;
    }
};