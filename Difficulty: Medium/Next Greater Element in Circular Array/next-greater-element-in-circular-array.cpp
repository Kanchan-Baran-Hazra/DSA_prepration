class Solution {
  public:
    vector<int> nextGreater(vector<int> &arr) {
        // code here
        priority_queue<int, vector<int>, greater<int>> pq;
        vector<int>ans;
        int n=arr.size();
        vector<int> temp = arr;
        arr.insert(arr.end(),temp.begin(),temp.end());
        for(int i=arr.size()-1;i>=0;i--){
            while(pq.size()>0 && pq.top()<=arr[i]){
                pq.pop();
            }
            if(i<=n-1){
                if(pq.size()==0){
                    ans.push_back(-1);
                }else{
                    ans.push_back(pq.top());
                }
            }
            pq.push(arr[i]);
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};