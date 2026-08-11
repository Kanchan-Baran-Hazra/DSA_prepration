class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        set<long long> st;

        int i = 0;

        for (int j = 0; j < nums.size(); j++) {

            // Keep at most indexDiff previous elements
            if (j - i > indexDiff) {
                st.erase(nums[i]);
                i++;
            }

            auto it = st.lower_bound((long long)nums[j]);

            // Check element >= nums[j]
            if (it != st.end() && *it - nums[j] <= valueDiff)
                return true;

            // Check element < nums[j]
            if (it != st.begin()) {
                --it;
                if (nums[j] - *it <= valueDiff)
                    return true;
            }

            st.insert(nums[j]);
        }

        return false;
    }
};