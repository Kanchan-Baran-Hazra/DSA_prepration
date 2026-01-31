class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string,char>mp;
        unordered_map<char,string>mp1;
        int i=0;
        int count=0;
        string st="";
        for(int j=0;j<s.size();j++){
            if(s[j]==' '){
                if(mp1.find(pattern[i])!=mp1.end() && mp1[pattern[i]]!=st) return false;
                if(mp.find(st)!=mp.end() && mp[st]!=pattern[i]) return false;
                mp1[pattern[i]]=st;
                mp[st]=pattern[i];
                i++;
                st="";
                count++;
            }else{
                st.push_back(s[j]);
                if(j==s.size()-1){
                    if(mp1.find(pattern[i])!=mp1.end() && mp1[pattern[i]]!=st) return false;
                    if(mp.find(st)!=mp.end() && mp[st]!=pattern[i]) return false;
                    count++;
                }
            }
        }
        if(count!=pattern.size()) return false;
        return true;
    }
};