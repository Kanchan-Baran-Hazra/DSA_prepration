// User function Template for C++

class Solution {
  public:
    int kthLargest(vector<int> &arr, int k) {
        // code here
        priority_queue<int> pq;
        for(int i=0;i<arr.size();i++){
            int sum=0;
            for(int j=i;j<arr.size();j++){
                sum+=arr[j];
                pq.push(sum);
            }
        }
        
        for(int i=1;i<k;i++){
            pq.pop();
        }
        
        return pq.top();
    }
};