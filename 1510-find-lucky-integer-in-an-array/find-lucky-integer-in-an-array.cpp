class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int>mp;

        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        int maxi=INT_MIN;
        for(auto x:mp){
            if(x.first==x.second) maxi=max(maxi,x.first);
        }

        return (maxi==INT_MIN)?-1:maxi;
    }
};