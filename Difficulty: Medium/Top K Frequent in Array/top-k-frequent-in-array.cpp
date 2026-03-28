class Solution {
  public:
    static bool emp(pair<int,int>a,pair<int,int>b){
        if(a.second==b.second) return a.first>b.first;
        return a.second>b.second;
    }
    vector<int> topKFreq(vector<int> &arr, int k) {
        // Code here
        vector<int>ans;
        unordered_map<int,int>mp;
        vector<pair<int,int>>temp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
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
