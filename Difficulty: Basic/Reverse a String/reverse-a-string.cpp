// User function Template for C++
class Solution {
  public:
    string reverseString(string& s) {
        // code here
        string ans="";
        for(int i=s.size()-1;i>=0;i--){
            ans.push_back(s[i]);
        }
        return ans;
    }
};
