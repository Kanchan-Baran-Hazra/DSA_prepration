class Solution {
public:
    int getMaxfreq(unordered_map<char, int>& mp) {
        int maxi = 0;
        for (auto x : mp) {
            maxi = max(maxi, x.second);
        }
        return maxi;
    }
    int getMinfreq(unordered_map<char, int>& mp) {
        int mini = INT_MAX;
        for (auto x : mp) {
            mini = min(mini, x.second);
        }
        return mini;
    }
    int beautySum(string s) {
        // Your code goes here
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            unordered_map<char, int> mp;
            for (int j = i; j < s.size(); j++) {
                mp[s[j]]++;
                int beauti = getMaxfreq(mp) - getMinfreq(mp);
                ans += beauti;
            }
        }
        return ans;
    }
};