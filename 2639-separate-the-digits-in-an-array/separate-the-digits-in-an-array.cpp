class Solution {
public:
    static vector<int> saparator(int n){
        vector<int>ans;
        while(n>0){
            int s=n%10;
            ans.push_back(s);
            n/=10;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            vector<int> temp=saparator(nums[i]);
            ans.insert(ans.end(),temp.begin(),temp.end());
        }

        return ans;
    }
};