class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        long long tsum=INT_MAX;
        for(int i=0;i<n;i++){
            int j=i+1;
            int k=n-1;
            while(j<k){
                long long sum=nums[i]+nums[j]+nums[k];
                if(abs(sum - target) < abs(tsum - target)) {
                    tsum = sum;
                }

                if(target>sum) j++;
                else if(target<sum) k--;
                else return sum;
            }
        }
        return tsum;
    }
};