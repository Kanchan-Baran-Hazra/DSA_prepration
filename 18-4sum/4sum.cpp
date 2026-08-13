class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        if(nums.size()<4) return ans;
        sort(nums.begin(),nums.end());
        int i=0;
        int n=nums.size();
        while(i<n-3){
            int j=i+1;
            while(j<n-2){
                int k=j+1;
                int l=n-1;
                while(k<l){
                    vector<int>sub;
                    long long sum=(long long)nums[i]+nums[j]+nums[k]+nums[l];
                    if(sum==target){
                        sub.push_back(nums[i]);
                        sub.push_back(nums[j]);
                        sub.push_back(nums[k]);
                        sub.push_back(nums[l]);
                        ans.push_back(sub);
                        k++;
                        l--;
                        while(k<l && nums[k]==nums[k-1]) k++;
                        while(k<l && nums[l]==nums[l+1]) l--;
                    }else if(sum<target) k++;
                    else l--;
                }
                j++;
                while(j<n-2 && nums[j]==nums[j-1]) j++;
            }
            i++;
            while(i<n-3 && nums[i]==nums[i-1]) i++;
        }
        return ans;
        
    }
};