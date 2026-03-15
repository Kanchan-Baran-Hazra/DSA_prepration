class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        // code here
        stack<int>pq;
        vector<int>ans;
        for(int i=0;i<arr.size();i++){
            while(pq.size()!=0 && arr[pq.top()]<=arr[i]){
                pq.pop();
            }
            if(pq.size()==0){
                ans.push_back(i+1);
            }else{
                ans.push_back(i-pq.top());
            }
            pq.push(i);
        }
        
        return ans;
    }
};