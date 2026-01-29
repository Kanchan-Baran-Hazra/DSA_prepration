class Solution {
  public:
    vector<vector<int>> countFreq(vector<int>& arr) {
        // code here
        vector<vector<int>>ans;
        int count=0;
        int num=-1;
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++){
            if(num==-1 || num==arr[i]){
                num=arr[i];
                count++;
            }else{
                vector<int>vec;
                vec.push_back(num);
                vec.push_back(count);
                ans.push_back(vec);
                num=arr[i];
                count=1;
            }
            if(i==arr.size()-1){
                vector<int>vec;
                vec.push_back(num);
                vec.push_back(count);
                ans.push_back(vec);
            }
        }
        return ans;
    }
};