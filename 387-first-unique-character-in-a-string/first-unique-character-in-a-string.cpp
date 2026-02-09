#include <bits/stdc++.h>
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int>mp;
        int j=0;
        for(int i=0;i<s.size();i++){
            if(mp.size()==0 || s[j]!=s[i]){
                mp[s[i]]++;
                continue;
            }
            mp[s[i]]++;
            while(j<s.size() && mp[s[j]]>1) j++;
        }
        if(j>=s.size()) return -1;
        return j;
    }
};