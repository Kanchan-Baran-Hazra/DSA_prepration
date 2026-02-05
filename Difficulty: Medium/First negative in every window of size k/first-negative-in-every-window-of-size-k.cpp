class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        // write code here
        int i=0;
        int j=0;
        vector<int>temp;
        vector<int>ans;
        while(j<arr.size()){
            if(arr[j]<0) temp.push_back(arr[j]);
            if(j-i+1<k){
                j++;
            }else{
                if(temp.size()!=0){
                    ans.push_back(temp[0]);
                    if(arr[i]==temp[0]) temp.erase(temp.begin());
                }else{
                    ans.push_back(0);
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};