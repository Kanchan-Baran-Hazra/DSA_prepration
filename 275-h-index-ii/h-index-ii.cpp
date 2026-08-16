class Solution {
public:
    static bool isposs(vector<int>& nums,int mid){
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=mid) count++;
        }
        return count>=mid;
    }
    int hIndex(vector<int>& nums) {
        int i=0;
        int j=nums.size();
        int ans=i;
        while(i<=j){
            int mid=i+(j-i)/2;

            if(isposs(nums,mid)){
                ans=mid;
                i=mid+1;
            }else j=mid-1;
        }
        return ans;
    }
};