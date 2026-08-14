class Solution {
public:
    string reverseVowels(string s) {
        unordered_map<char, int> mp;
        mp['a']++;
        mp['e']++;
        mp['i']++;
        mp['o']++;
        mp['u']++;

        mp['A']++;
        mp['E']++;
        mp['I']++;
        mp['O']++;
        mp['U']++;

        int i = 0;
        int j = s.size() - 1;
        while (i < j) {
            if (mp.find(s[i]) != mp.end() && mp.find(s[j]) != mp.end()) {
                swap(s[i], s[j]);
                i++;
                j--;
            } else if (mp.find(s[i]) != mp.end() && mp.find(s[j]) == mp.end()) {
                j--;
            } else if (mp.find(s[i]) == mp.end() && mp.find(s[j]) != mp.end()) {
                i++;
            } else {
                i++;
                j--;
            }
        }
        return s;
    }
};