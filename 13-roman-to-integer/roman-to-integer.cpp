class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int>mp;
        mp['I']=1;
        mp['V']=5;
        mp['X']=10;
        mp['L']=50;
        mp['C']=100;
        mp['D']=500;
        mp['M']=1000;

        int ans=0;
        int j=-1;
        for(int i=0;i<s.size();i++){
            if(j>=0 && mp[s[j]]<mp[s[i]]){
                ans+=(mp[s[i]]-mp[s[j]]);
                ans-=mp[s[j]];
            }else ans+=mp[s[i]];

            j++;
        }

        return ans;
    }
};