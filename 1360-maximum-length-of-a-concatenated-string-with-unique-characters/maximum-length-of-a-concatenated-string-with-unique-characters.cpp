#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool isdup(string s1, string s2) {
        unordered_map<char, int> mp;
        for (int i = 0; i < s1.size(); i++) {
            if (mp.find(s1[i]) != mp.end()) return false;
            mp[s1[i]]++;
        }

        for (int i = 0; i < s2.size(); i++) {
            if (mp.find(s2[i]) != mp.end()) return false;
            mp[s2[i]]++;
        }

        return true;
    }

    int helper(vector<string>& arr, int i, int n, string s, unordered_map<string, int>& dp) {
        if (i == n) return 0;

        // Combine index 'i' and current string 's' as a unique state key
        string key = to_string(i) + "#" + s;
        if (dp.find(key) != dp.end()) return dp[key];

        if (isdup(s, arr[i])) {
            return dp[key] = max((int)arr[i].size() + helper(arr, i + 1, n, s + arr[i], dp), helper(arr, i + 1, n, s, dp));
        } else {
            return dp[key] = helper(arr, i + 1, n, s, dp);
        }
    }

public:
    int maxLength(vector<string>& arr) {
        unordered_map<string, int> dp;
        return helper(arr, 0, arr.size(), "", dp);
    }
};