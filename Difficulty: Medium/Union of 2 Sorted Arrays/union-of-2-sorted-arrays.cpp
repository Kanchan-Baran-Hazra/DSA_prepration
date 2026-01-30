class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // code here
        int i=0;
        int j=0;
        int n=a.size();
        int m=b.size();
        vector<int>ans;
        while(1){
            if(i>=n || j>=m) break;
            else if(a[i]==b[j]){
                ans.push_back(a[i]);
                while(ans[ans.size()-1]==a[i])
                i++;
                while(ans[ans.size()-1]==b[j])
                j++;
            }else if(a[i]<b[j]){
                ans.push_back(a[i]);
                while(ans[ans.size()-1]==a[i])
                i++;
            }else if(a[i]>b[j]){
                ans.push_back(b[j]);
                while(ans[ans.size()-1]==b[j])
                j++;
            }
        }
        
        while(i<n){
            if(ans[ans.size()-1]!=a[i]){
                ans.push_back(a[i]);
                while(ans[ans.size()-1]==a[i])
                i++;
            }
        }
        
        while(j<m){
            if(ans[ans.size()-1]!=b[j]){
                ans.push_back(b[j]);
                while(ans[ans.size()-1]==b[j])
                j++;
            }
        }
        
        return ans;
    }
};