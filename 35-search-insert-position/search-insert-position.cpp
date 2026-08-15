#include <bits/stdc++.h>
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        auto x= lower_bound(nums.begin(),nums.end(),target);
        return x-nums.begin();
    }
};