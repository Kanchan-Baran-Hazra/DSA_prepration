class Solution {
  public:
    vector<int> prevSmaller(vector<int>& arr) {
        //  code here
        priority_queue<int>pq;
        vector<int>ans;
        for(int i=0;i<arr.size();i++){
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
        return ans;
    }
};