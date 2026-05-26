class Solution {
public:
    static bool isPalindrome(string& s, int start, int end) {

        while (start < end) {

            if (s[start] != s[end])
                return false;

            start++;
            end--;
        }

        return true;
    }

    static void helper(string &s, int idx, vector<string> sub,
                       vector<vector<string>>& ans) {
        if (idx >= s.size()) {
            ans.push_back(sub);
            return;
        }

        for (int i = idx; i < s.size(); i++) {
            if (isPalindrome(s,idx,i)){
                sub.push_back(s.substr(idx,i-idx+1));
                helper(s,i+1,sub,ans);
                sub.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> sub;
        helper(s, 0, sub, ans);
        return ans;
    }
};