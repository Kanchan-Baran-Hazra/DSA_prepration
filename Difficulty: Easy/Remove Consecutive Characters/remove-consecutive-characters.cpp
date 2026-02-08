class Solution {
  public:
    string removeConsecutiveCharacter(string& s) {
        // code here.
        string ans="";
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(st.size()==0 || st.top()!=s[i]){
                st.push(s[i]);
            }
        }
        
        while(st.size()!=0){
            ans.push_back(st.top());
            st.pop();
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};