class Solution {
  public:
    string maxOdd(string s) {
        // code here
        string ans="";
        for(int i=s.size()-1;i>=0;i--){
            if((s[i]-'0')%2!=0){
                for(int j=0;j<=i;j++){
                    ans.push_back(s[j]);
                }
                break;
            }
        }
        return ans;
    }
};