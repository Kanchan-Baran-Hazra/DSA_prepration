class Solution {
  public:
    int findLower(vector<int>& arr, int j, int x){
        int i=0;
        int ans=j;
        
        while(i<=j){
            int mid=i+(j-i)/2;
            
            if(arr[mid]==x){
                ans=mid;
                j=mid-1;
            }else i=mid+1;
        }
        
        return ans;
    }
    
    int finfUpper(vector<int>& arr, int i, int x){
        int j=arr.size()-1;
        int ans=arr.size();
        
        while(i<=j){
            int mid=i+(j-i)/2;
            
            if(arr[mid]>x){
                ans=mid;
                j=mid-1;
            }else i=mid+1;
        }
        
        return ans;
    }
    
    vector<int> find(vector<int>& arr, int x) {
        // code here
        vector<int>ans;
        if(arr[arr.size()-1]<x){
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        if(arr[0]>x){
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        int i=0;
        int j=arr.size()-1;
        
        while(i<=j){
            int mid=i+(j-i)/2;
            
            if(arr[mid]==x){
                int low=findLower(arr,mid,x);
                int upper=finfUpper(arr,mid+1,x);
                ans.push_back(low);
                ans.push_back(upper-1);
                return ans;
            }else if(arr[mid]<x) i=mid+1;
            else j=mid-1;
        }
        
        ans.push_back(-1);
        ans.push_back(-1);
        return ans;
    }
};