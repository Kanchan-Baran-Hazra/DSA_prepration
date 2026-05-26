class Solution {
public:
    static bool isvalid(string s) {
        int i = 0;
        if (s[i] == '0')
            return false;
        if (stoi(s) > 255)
            return false;

        return true;
    }
    static void helper(string s, int idx, string sub, vector<string>& ans,
                       int part) {
        if (part > 4) {
            return;
        }
        if (idx == s.size() && part == 4) {
            sub.pop_back();
            ans.push_back(sub);
            return;
        }

        if (idx + 1 <= s.size()) {
            helper(s, idx + 1, sub + s.substr(idx, 1) + '.', ans, part + 1);
        }

        if (idx + 2 <= s.size() && isvalid(s.substr(idx, 2))) {
            helper(s, idx + 2, sub + s.substr(idx, 2) + '.', ans, part + 1);
        }

        if (idx + 3 <= s.size() && isvalid(s.substr(idx, 3))) {
            // sub.push_back(s[idx + 2]);
            helper(s, idx + 3, sub + s.substr(idx, 3) + '.', ans, part + 1);
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        if (s.size() > 12)
            return ans;
        string sub = "";
        helper(s, 0, sub, ans, 0);

        return ans;
    }
};