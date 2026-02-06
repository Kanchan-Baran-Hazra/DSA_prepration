class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        // code here
        int i=0;
        int j=0;
        int ans=0;
        unordered_map<char,int>mp;
        while(j<s.size()){
            if(mp.find(s[j])==mp.end()){
                mp[s[j]]++;
                int size=mp.size();
                ans=max(ans,size);
            }else{
                while(mp.find(s[j])!=mp.end()){
                    mp[s[i]]--;
                    if(mp[s[i]]==0) mp.erase(s[i]);
                    i++;
                }
                mp[s[j]]++;
            }
            j++;
        }
        return ans;
    }
};
