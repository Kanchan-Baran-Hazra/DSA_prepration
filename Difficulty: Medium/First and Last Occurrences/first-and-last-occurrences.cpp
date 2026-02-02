class Solution {
  public:
    vector<int> find(vector<int>& arr, int x) {
        // code here
        vector<int>ans;
        ans.push_back(-1);
        ans.push_back(-1);
        int i=0;
        int j=arr.size()-1;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(arr[mid]==x){
                int n=mid;
                int m=mid;
                while(n>0 && arr[n-1]==x) n--;
                while(m<arr.size()-1 && arr[m+1]==x) m++;
                ans[0]=n;
                ans[1]=m;
                return ans;
            }else if(arr[mid]<x) i=mid+1;
            else j=mid-1;
        }
        return ans;
    }
};