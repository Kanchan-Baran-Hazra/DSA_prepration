class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.size();
        vector<int> a(n);
        vector<int> b(n);
        int count=0;

        for(int i=0;i<n;i++){
            if(s[i]=='b') count++;
            a[i]=count;
        }

        count=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='a') count++;
            b[i]=count;
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            ans=min(ans,a[i]+b[i]-1);
        }
        return ans;
    }
};