class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        // code here
        unordered_map<char,int>mp;
        int ans=0;
        
        int i=0;
        int j=0;
        while(i<s.size()){
            while(j<=i && mp.find(s[i])!=mp.end()){
                mp[s[j]]--;
                if(mp[s[j]]==0) mp.erase(s[j]);
                j++;
            }
            ans=max(ans,i-j+1);
            mp[s[i]]++;
            i++;
        }
        
        return ans;
    }
};
