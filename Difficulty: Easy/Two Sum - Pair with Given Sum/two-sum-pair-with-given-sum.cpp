class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        // code here
        if(arr.size()==1) return false;
        unordered_map<int,int>mp;
        for(int i=0;i<arr.size();i++){
            if(mp.find(target-arr[i])!=mp.end()) return true;
            mp[arr[i]]++;
        }
        return false;
    }
};