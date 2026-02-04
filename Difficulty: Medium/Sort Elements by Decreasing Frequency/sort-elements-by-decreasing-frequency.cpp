class Solution {
  public:
    // Complete this function
    // Function to sort the array according to frequency of elements.
    static bool cmp(pair<int,int>a,pair<int,int>b){
        if(a.second!=b.second){
            return a.second>b.second;
        }
        return a.first<b.first;
        
    }
    vector<int> sortByFreq(vector<int>& arr) {
        // Your code here
        unordered_map<int,int>mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        vector<pair<int,int>>temp;
        vector<int>ans;
        for(auto x:mp){
            temp.push_back(x);
        }
        sort(temp.begin(),temp.end(),cmp);
        for(int i=0;i<temp.size();i++){
            for(int j=0;j<temp[i].second;j++){
                ans.push_back(temp[i].first);
            }
        }
        return ans;
    }
};