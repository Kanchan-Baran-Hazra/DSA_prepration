class Solution {
public:
    static void helper(string &digits,unordered_map<char,string>& mp,vector<string>& ans,int i,string &temp){
        if(i>=digits.size()){
            ans.push_back(temp);
            return;
        }
        string s=mp[digits[i]];

        for(int j=0;j<s.size();j++){
            temp.push_back(s[j]);
            helper(digits,mp,ans,i+1,temp);
            temp.pop_back();
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string>mp;
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";

        vector<string> ans;
        string temp="";
        helper(digits,mp,ans,0,temp);

        return ans;

    }
};