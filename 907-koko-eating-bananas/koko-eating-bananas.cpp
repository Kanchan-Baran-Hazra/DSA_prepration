class Solution {
public:
    static bool caneat(vector<int>& nums,int mid,int h){
        long long time_take=0;
        for(int i=0;i<nums.size();i++){
            double num=(double)nums[i]/mid;
            int time=ceil(num);
            time_take+=time;
        }
        return time_take<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        int i=1;
        int j = *max_element(piles.begin(), piles.end());
        int ans=j;
        while(i<=j){
            long long mid=i+(j-i)/2;

            if(caneat(piles,mid,h)){
                ans=mid;
                j=mid-1;
            }
            else i=mid+1;
        }

        return ans;
    }
};