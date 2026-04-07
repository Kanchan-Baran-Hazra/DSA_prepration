class Solution {
  public:
    static bool emp(pair<char,int> &a,pair<char,int> &b){
        if(a.second==b.second){
            return a.first<b.first;
        }
        
        return a.second<b.second;
    }
    string frequencySort(string &s) {
        // code here
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        
        vector<pair<char,int>>temp;
        for(auto x:mp){
            temp.push_back(x);
        }
        
        string ans;
        
        sort(temp.begin(),temp.end(),emp);
        
        for(int i=0;i<temp.size();i++){
            for(int j=0;j<temp[i].second;j++){
                ans.push_back(temp[i].first);
            }
        }
        
        return ans;
    }
};