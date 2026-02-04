class Solution {
  public:
    void helper(string s,vector<string> &ans,string &sub,int i){
        if(i==s.size()){
            ans.push_back(sub);
            return;
        }
        sub.push_back(s[i]);
        helper(s,ans,sub,i+1);
        sub.pop_back();
        helper(s,ans,sub,i+1);
    }
    
    vector<string> AllPossibleStrings(string s) {
        // Code here
        vector<string> ans;
        int i=0;
        string sub="";
        helper(s,ans,sub,i);
        sort(ans.begin(),ans.end());
        return ans;
    }
};