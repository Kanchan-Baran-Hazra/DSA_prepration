class Solution {
  public:
    // Function to count the number of subarrays with a sum that is divisible by K
    int subCount(vector<int>& arr, int k) {
        // Your code goes here
        unordered_map<int,int>mp;
        vector<int>temp;
        long sum=0;
        int ans=0;
        mp[sum]++;
        // for(int i=0;i<arr.size();i++){
        //     sum+=arr[i];
        //     temp.push_back(sum);
        // }
        
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            int req=sum%k;
            if(req<0){
                req=(req%k)+k;
            }
            if(mp.find(req)!=mp.end()){
                ans+=mp[req];
            }
            mp[req]++;
        }
        return ans;
    }
};
