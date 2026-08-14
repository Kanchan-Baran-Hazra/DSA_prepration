class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char,int>mp;
        int i=0;
        int j=0;
        int n=s.size();
        int ans=0;
        while(j<n){
            if(mp.find(s[j])!=mp.end() && mp[s[j]]>1){
                while(i<=j && mp[s[j]]>1){
                    mp[s[i]]--;
                    if(mp[s[i]]==0) mp.erase(s[i]);
                    i++;
                }
            }
            mp[s[j]]++;
            ans=max(ans,j-i+1);
            j++;
        }

        return ans;
    }
};