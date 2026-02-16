class Solution {
  public:
    int maxConsecBits(vector<int> &arr) {
        // code here
        int ans=0;
        int num=-1;
        int count=0;
        for(int i=0;i<arr.size();i++){
            if(num!=arr[i]){
                num=arr[i];
                count=1;
                ans=max(ans,count);
            }else{
                count++;
                ans=max(ans,count);
            }
        }
        return ans;
    }
};