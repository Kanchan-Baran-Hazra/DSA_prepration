class Solution {
public:
    static bool emp(pair<string,int> &a,pair<string,int> &b){
        if(a.second==b.second){
            return a.first<b.first;
        }
        return a.second>b.second;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string>ans;
        unordered_map<string,int>mp;
        vector<pair<string,int>>temp;

        for(int i=0;i<words.size();i++){
            mp[words[i]]++;
        }

        for(auto x:mp){
            temp.push_back(x);
        }

        sort(temp.begin(),temp.end(),emp);

        for(int i=0;i<k;i++){
            ans.push_back(temp[i].first);
        }

        return ans;
    }
};