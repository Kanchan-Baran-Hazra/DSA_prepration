class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        int i=0;
        int j=0;
        vector<int>pq;
        vector<int>ans;
        while(j<arr.size()){
            while(pq.size()!=0 && pq.back()<arr[j]) pq.pop_back();
            pq.push_back(arr[j]);
            if(j-i+1<k) j++;
            else{
                ans.push_back(pq[0]);
                if(arr[i]==pq[0]) pq.erase(pq.begin());
                i++;
                j++;
            }
        }
        return ans;
    }
};