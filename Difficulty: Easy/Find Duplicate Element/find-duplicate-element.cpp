class Solution {
  public:
    int findDuplicate(vector<int>& arr) {
        // Your code goes here
        int count=0;
        int ans=-1;
        for(int i=0;i<10;i++){
            if(count==0){
                count++;
                ans=arr[i];
            }else if(ans==arr[i]) count++;
            else count--;
        }
        return ans;
    }
};
