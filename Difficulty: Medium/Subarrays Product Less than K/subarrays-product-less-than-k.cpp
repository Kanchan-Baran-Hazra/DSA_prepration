

class Solution {
  public:
    long long countSubArrayProductLessThanK(const vector<int>& arr, int n, long long k) {
        if(k<=1) return 0;
        int i=0;
        int j=0;
        long long ans=0;
        long long prod=1;
        while(j<n){
            prod*=arr[j];
            
            while(prod>=k){
                prod/=arr[i];
                i++;
            }
            
            ans+=(j-i)+1;
            j++;
        }
        return ans;
    }
};