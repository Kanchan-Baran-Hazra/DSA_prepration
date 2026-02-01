class Solution {
public:
    string getString(string &s,int j,int k){
        string ans="";
        for(int i=k;i<=j;i++){
            ans.push_back(s[i]);
        }
        return ans;
    }
    string longestPalindrome(string s) {
        string ans="";
        ans.push_back(s[0]);
        for(int i=1;i<s.size();i++){
            int j=i+1;
            int k=i-1;
            while(k>=0 && j<s.size() && s[j]==s[k]){
                j++;
                k--;
            }
            string temp=getString(s,j-1,k+1);
            if(temp.size()>ans.size()){
                ans=temp;
            }
            j=i;
            k=i-1;
            while(k>=0 && j<s.size() && s[j]==s[k]){
                j++;
                k--;
            }
            temp=getString(s,j-1,k+1);
            if(temp.size()>ans.size()){
                ans=temp;
            }
        }
        return ans;
    }
};