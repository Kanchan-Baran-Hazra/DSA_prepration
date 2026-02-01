// User function template for C++
class Solution {
  public:

    string removeDups(string &s) {
        // Your code goes here
        unordered_map<char,int>mp;
        string ans="";
        for(int i=0;i<s.size();i++){
            if(mp.find(s[i])!=mp.end()) continue;
            mp[s[i]]++;
            ans.push_back(s[i]);
        }
        return ans;
    }
};