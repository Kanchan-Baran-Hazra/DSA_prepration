class Solution {
  public:
    bool areAnagrams(string& s1, string& s2) {
        // code here
        if(s1.size()!=s2.size()) return false;
        unordered_map<char,int>mp;
        for(auto ch:s1){
            mp[ch]++;
        }
        
        for(auto ch:s2){
            mp[ch]--;
            if(mp[ch]==0)
            mp.erase(ch);
        }
        if(mp.size()==0) return true;
        return false;
    }
};