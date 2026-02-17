class Solution {
  public:
    int smallestSubWithSum(int x, vector<int>& arr) {
        // Your code goes here
        int i=0;
        int j=0;
        long long sum=0;
        int ans=INT_MAX;
        while(j<arr.size()){
            sum+=arr[j];
            
            while(sum>x){
                ans=min(ans,j-i+1);
                sum-=arr[i];
                i++;
            }
            j++;
        }
        
        while(sum>x){
            ans=min(ans,j-i+1);
            sum-=arr[i];
            i++;
        }
        
        return (ans==INT_MAX)? 0:ans;
    }
};