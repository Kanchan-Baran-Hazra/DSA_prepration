// User function Template for C++

class Solution {
  public:
    string preToInfix(string pre_exp) {
        // Write your code here
        reverse(pre_exp.begin(),pre_exp.end());
        stack<string>st;
        string ans="";
        
        for(int i=0;i<pre_exp.size();i++){
            if(isalnum(pre_exp[i])){
                st.push(string(1,pre_exp[i]));
            }else{
                string left = st.top(); st.pop();
                string right  = st.top(); st.pop();
                
                string temp = string("(") + left + pre_exp[i] + right + ")";
                st.push(temp);
            }
        }
        
        while(st.size()!=0){
            ans+=st.top();
            st.pop();
        }
        
        return ans;
    }
};