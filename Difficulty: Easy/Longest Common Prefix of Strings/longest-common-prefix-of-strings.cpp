// User function template for C++
class Solution {
  public:
    string longestCommonPrefix(vector<string> arr) {
        // your code here
        string small;
        int small_len=INT_MAX;
        for(int i=0;i<arr.size();i++){
            if(arr[i].size()<small_len){
                small=arr[i];
                small_len=arr[i].size();
            }
        }
        string ans="";
        for(int i=0;i<small.size();i++){
            int count=0;
            ans.push_back(small[i]);
            for(int j=0;j<arr.size();j++){
                if(arr[j].find(ans)==0) count++;
            }
            if(count!=arr.size()){
                ans.pop_back();
                return ans;
            }
            count=0;
        }
    }
};