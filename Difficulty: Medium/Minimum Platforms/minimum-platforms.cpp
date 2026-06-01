class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        // code here
        vector<pair<int,int>>vec;
        for(int i=0;i<arr.size();i++){
            vec.push_back({arr[i],dep[i]});
        }
        sort(vec.begin(),vec.end());
        int ans=0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=0;i<vec.size();i++){
            while(pq.size()!=0 && pq.top()<vec[i].first){
                pq.pop();
            }
            pq.push(vec[i].second);
            int y=pq.size();
            ans=max(ans,y);
        }
        return ans;
    }
};
