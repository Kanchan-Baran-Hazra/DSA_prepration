class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        //  code here
        priority_queue<int>pq;
        vector<int>ans;
        for(int i=arr.size()-1;i>=0;i--){
            while(pq.size()!=0 && pq.top()>=arr[i]){
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