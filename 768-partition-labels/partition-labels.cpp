class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>ans;
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]=i;
        }
        int idx=0;
        while(idx!=s.size()){
            int start=idx;
            for(int i=idx;i<=idx;i++){
                if(idx<mp[s[i]]) idx=mp[s[i]];
            }
            ans.push_back(idx+1-start);
            idx++;
        }

        return ans;
    }
};