class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i=0;
        int j=nums.size()-1;
        vector<int>ans;
        while(i<=j){
            if(pow(nums[i],2)<=pow(nums[j],2)){
                ans.insert(ans.begin(), pow(nums[j],2));
                j--;
            }else{
                ans.insert(ans.begin(), pow(nums[i],2));
                i++;;
            }
        }
        return ans;
    }
};