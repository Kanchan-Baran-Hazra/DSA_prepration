class Solution {
  public:
    int atmostK(vector<int> &arr, int k){
        if(k==0) return 0;
        int i=0;
        int j=0;
        int ans=0;
        unordered_map<int,int>mp;
        while(j<arr.size()){
            mp[arr[j]]++;
            
            while(mp.size()>k){
                mp[arr[i]]--;
                if(mp[arr[i]]==0) mp.erase(arr[i]);
                i++;
            }
            
            if(mp.size()<=k) ans+=j-i+1;
            j++;
        }
        return ans;
    }
    
    int exactlyK(vector<int> &arr, int k) {
        // code here
        return atmostK(arr,k)-atmostK(arr,k-1);
    }
};