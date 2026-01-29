class Solution {
  public:
    vector<int> removeDuplicates(vector<int> &arr) {
        // code here
        if(arr.size()==1)
        return arr;
        vector<int>ans;
        for(int i=0;i<arr.size();i++){
            if(ans.size()==0 || ans[ans.size()-1]!=arr[i])
            ans.push_back(arr[i]);
        }
        return ans;
    }
};