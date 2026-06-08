class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<bool>temp(nums.size(),false);

        for(int i=0;i<nums.size();i++){
            temp[nums[i]-1]=true;
        }

        vector<int>ans;
        for(int i=0;i<temp.size();i++){
            if(!temp[i]) ans.push_back(i+1);
        }

        return ans;
    }
};