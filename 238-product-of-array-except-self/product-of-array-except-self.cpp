class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>ans;
        vector<int>pref;
        vector<int>suf;
        int prod=1;
        for(int i=0;i<nums.size();i++){
            prod=prod*nums[i];
            pref.push_back(prod);
        }
        prod=1;
        for(int i=nums.size()-1;i>=0;i--){
            prod=prod*nums[i];
            suf.push_back(prod);
        }
        // for(int i=0;i<nums.size();i++){
        //     cout<<pref[i]<<endl;
        // }
        reverse(suf.begin(),suf.end());
        for(int i=0;i<nums.size();i++){
            if(i==0){
                ans.push_back(suf[i+1]);
            }else if(i==nums.size()-1){
                ans.push_back(pref[i-1]);
            }else{
                ans.push_back(pref[i-1]*suf[i+1]);
            }
        }
        return ans;
    }
};