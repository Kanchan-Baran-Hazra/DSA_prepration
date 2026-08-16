class Solution {
public:
    static int isposs(vector<int>& nums,int sum){
        int num_sum=1;
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(count+nums[i]>sum){
                num_sum++;
                count=0;
            }
            count+=nums[i];
        }

        return num_sum;
    }
    int splitArray(vector<int>& nums, int k) {
        int mini=0;
        int maxi=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mini=max(mini,nums[i]);
            maxi+=nums[i];
        }
        int i=mini;
        int j=maxi;
        int ans=i;

        while(i<=j){
            int mid=i+(j-i)/2;

            int need=isposs(nums,mid);
            if(need<=k){
                j=mid-1;
            }
            else i=mid+1;
        }

        return i;
    }
};