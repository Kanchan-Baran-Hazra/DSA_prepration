class Solution {
public:
    static bool cmp(string& s1, string& s2) { return s1 + s2 > s2 + s1; }
    string largestNumber(vector<int>& nums) {
        vector<string> vec;
        for (int i = 0; i < nums.size(); i++) {
            vec.push_back(to_string(nums[i]));
        }

        sort(vec.begin(), vec.end(), cmp);
        string ans = "";
        for (int i = 0; i < vec.size(); i++) {
            ans += vec[i];
        }
        bool isZero = true;
        for (char c : ans) {
            if (c != '0') {
                isZero = false;
                break;
            }
        }

        if (isZero)
            ans = "0";
        return ans;
    }
};