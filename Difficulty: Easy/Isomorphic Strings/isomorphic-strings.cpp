class Solution {
  public:
    bool areIsomorphic(string &s1, string &s2) {
        // code here
        if(s1.size()!=s2.size()) return false;
        
        unordered_map<char,char>mp,mp1;
        
        for(int i=0;i<s1.size();i++){
            if(mp.find(s1[i])!=mp.end()){
                if(mp[s1[i]]!=s2[i]) return false;
            }else if(mp1.find(s2[i])!=mp1.end()){
                if(mp1[s2[i]]!=s1[i]) return false;
            }
            else{
                mp[s1[i]]=s2[i];
                mp1[s2[i]]=s1[i];
            }
        }
        return true;
    }
};