class Solution {
public:
    static bool isposs(vector<int>& nums,int mid,int days){
        int taken_day=1;
        long long count=0;
        for(int i=0;i<nums.size();i++){
            if((count+nums[i])>mid){
                taken_day++;
                count=0;
            }
            count+=nums[i];
        }

        return taken_day<=days;
    }
    int shipWithinDays(vector<int>& nums, int days) {
        int n=nums.size();
        int j=accumulate(nums.begin(),nums.end(),0);
        int i=*max_element(nums.begin(),nums.end());
        int ans=j;

        while(i<=j){
            int mid=i+(j-i)/2;

            if(isposs(nums,mid,days)){
                ans=mid;
                j=mid-1;
            }else i=mid+1;
        }

        return ans;
    }
};