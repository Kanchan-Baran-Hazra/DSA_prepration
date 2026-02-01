class Solution {
public:
    int lengthOfLastWord(string s) {
        string ans="";
        for(int i=s.size()-1;i>=0;i--){
            if(ans.size()!=0 && isspace(s[i])) return ans.size();
            if(ans.size()==0 && isspace(s[i])) continue;
            if(isalpha(s[i])){
                ans.push_back(s[i]);
            }
        }
        return ans.size();
    }
};