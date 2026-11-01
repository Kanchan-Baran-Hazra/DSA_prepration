class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pref=1;
        int sufx=1;
        int n=nums.size();
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(pref==0) pref=1;
            if(sufx==0) sufx=1;
            pref=pref*nums[i];
            sufx=sufx*nums[n-i-1];
            maxi=max(maxi,max(pref,sufx));
        }
        return maxi;
    }
};