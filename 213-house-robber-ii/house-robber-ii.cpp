class Solution {
public:
    static int helper(vector<int>& nums,int st,int ed){
        int n=ed-st+1;
        vector<int> dp(n,-1);
        dp[0]=nums[st];
        dp[1]=max(nums[st+1],nums[st]);

        for(int j=st+2,i=2;j<=ed;j++,i++){
            dp[i]=max(nums[j]+dp[i-2],dp[i-1]);
        }

        return dp[n-1];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();

        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);

        return max(helper(nums,0,n-2),helper(nums,1,n-1));
    }
};