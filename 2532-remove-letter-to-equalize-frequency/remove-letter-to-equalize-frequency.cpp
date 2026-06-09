class Solution {
public:
    bool equalFrequency(string word) {
        for (int i = 0; i < word.size(); i++) {
            unordered_map<char,int> mp;

            for (int j = 0; j < word.size(); j++) {
                if (j != i) mp[word[j]]++;
            }

            int freq = -1;
            bool ok = true;

            for (auto &p : mp) {
                if (freq == -1) freq = p.second;
                else if (freq != p.second) {
                    ok = false;
                    break;
                }
            }

            if (ok) return true;
        }

        return false;
    }
};