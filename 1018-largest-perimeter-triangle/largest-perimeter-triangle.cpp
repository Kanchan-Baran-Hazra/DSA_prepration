class Solution {
public:
    static bool isposs(int i,int j,int k){
        int larg=max(i,max(j,k));

        if(larg==i) return i<j+k;
        else if(larg==j) return j<i+k;
        else return k<i+j;
        
    }
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();

        int i=0;
        int j=i+1;
        int k=i+2;
        int ans=0;
        while(k<n){
            if(isposs(nums[i],nums[j],nums[k])) ans=max(ans,nums[i]+nums[j]+nums[k]);
            i++;
            j++;
            k++;
        }

        return ans;
    }
};