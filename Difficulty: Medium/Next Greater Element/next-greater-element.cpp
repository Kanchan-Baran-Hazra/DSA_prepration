class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        // code here
        priority_queue<int, vector<int>, greater<int>>pq;
        vector<int>ans;
        for(int i=arr.size()-1;i>=0;i--){
            while(pq.size()!=0 && arr[i]>=pq.top()){
                pq.pop();
            }
            if(pq.size()==0){
                ans.push_back(-1);
            }else{
                ans.push_back(pq.top());
            }
            pq.push(arr[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};