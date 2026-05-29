class Solution {
public:
    static int sumofdig(int nums){
        int sum=0;
        while(nums>0){
            sum+=nums%10;
            nums/=10;
        }
        return sum;
    }
    int minElement(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> mp;
        for(int i=0;i<nums.size();i++){
            mp.push(sumofdig(nums[i]));
        }

        return mp.top();
    }
};