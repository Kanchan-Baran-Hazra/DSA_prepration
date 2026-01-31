class Solution {
  public:
    int findUnique(int k, vector<int>& arr) {
        // code here
        unordered_map<int,int>mp;
        for(int x:arr)
        mp[x]++;
        
        for(int i=0;i<arr.size();i++){
            if(mp[arr[i]]!=k){
                return arr[i];
            }
        }
        return -1;
    }
};