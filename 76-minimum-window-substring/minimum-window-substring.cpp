class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size())
            return "";
        int i = 0;
        int j = 0;
        unordered_map<char, int> mp;
        for (int i = 0; i < t.size(); i++) {
            mp[t[i]]++;
        }
        string ans;
        int count = mp.size();
        int start = 0;        // store best window start
        int minLen = INT_MAX; // store best length
        while (j < s.size()) {
            if (mp.find(s[j]) != mp.end()) {
                mp[s[j]]--;
                if (mp[s[j]] == 0)
                    count--;
                while (count == 0) {
                    if (j - i + 1 < minLen) {
                        minLen = j - i + 1;
                        start = i;
                    }
                    if (mp.find(s[i]) != mp.end()) {
                        mp[s[i]]++;
                        if (mp[s[i]] > 0)
                            count++;
                    }
                    i++;
                }
            }
            j++;
        }

        while (count == 0) {
            if (j - i + 1 < minLen) {
                minLen = j - i + 1;
                start = i;
            }
            if (mp.find(s[i]) != mp.end()) {
                mp[s[i]]++;
                if (mp[s[i]] > 0)
                    count++;
            }
            i++;
        }
        return (minLen==INT_MAX)? "":s.substr(start,minLen);
    }
};