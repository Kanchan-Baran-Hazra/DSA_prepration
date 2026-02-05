class Solution {
  public:
    static bool cmp(pair<int,int>a,pair<int,int>b){
        if(a.second!=b.second){
            return a.second>b.second;
        }
        return a.first>b.first;
    }
    vector<int> topKFreq(vector<int> &arr, int k) {
        // Code here
        unordered_map<int,int>mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        vector<pair<int,int>>temp;
        for(auto x:mp){
            temp.push_back(x);
        }
        sort(temp.begin(),temp.end(),cmp);
        vector<int>ans;
        for(int i=0;i<k;i++){
            ans.push_back(temp[i].first);
        }
        return ans;
    }
};
