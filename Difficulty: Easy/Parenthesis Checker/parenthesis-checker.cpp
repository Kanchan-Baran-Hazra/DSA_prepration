class Solution {
  public:
    bool isBalanced(string& s) {
        // code here
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(st.size()==0 || s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
            }else{
                if(s[i]==')' && st.top()=='('){
                    st.pop();
                }else if(s[i]=='}' && st.top()=='{'){
                    st.pop();
                }else if(s[i]==']' && st.top()=='['){
                    st.pop();
                }else{
                    return false;
                }
            }
        }
        
        return st.size()==0;
    }
};