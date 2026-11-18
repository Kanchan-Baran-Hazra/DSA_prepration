class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxi=0;
        int i=0;
        int j=0;
        unordered_map<char,int>mp;
        while(i<s.size()){
            if(mp.find(s[i])==mp.end()){
                mp[s[i]]++;
                i++;
                maxi=max(maxi,i-j);
            }else{
                while(mp.find(s[i])!=mp.end()){
                    mp[s[j]]--;
                    if(mp[s[j]]==0) mp.erase(s[j]);
                    j++;
                }
                mp[s[i]]++;
                i++;
                maxi=max(maxi,i-j);
            }
        }

        return maxi;
    }
};