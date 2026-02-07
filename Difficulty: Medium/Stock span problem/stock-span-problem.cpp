class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        // code here
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int>ans;
        for(int i=0;i<arr.size();i++){
            while(pq.size()!=0 && pq.top().first<=arr[i]){
                pq.pop();
            }
            if(pq.size()==0){
                ans.push_back(i+1);
            }else{
                ans.push_back(i-pq.top().second);
            }
            pq.push({arr[i],i});
        }
        return ans;
    }
};