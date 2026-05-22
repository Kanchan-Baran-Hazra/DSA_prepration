class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        if(arr.size()==1) return 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i=0;i<arr.size();i++){
            pq.push(arr[i]);
        }
        
        int ans=0;
        
        while(pq.size()>1){
            int ff=pq.top();
            pq.pop();
            int sf=pq.top();
            pq.pop();
            int sum=sf+ff;
            ans+=sum;
            pq.push(sum);
        }
        
        return ans;
    }
};