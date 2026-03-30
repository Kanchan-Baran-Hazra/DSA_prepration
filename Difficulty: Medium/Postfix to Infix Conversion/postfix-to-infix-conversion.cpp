// User function Template for C++

class Solution {
  public:
    string postToInfix(string &post_exp) {
        // Write your code here
        stack<string>st;
        string ans="";
        
        for(int i=0;i<post_exp.size();i++){
            if(isalnum(post_exp[i])){
                st.push(string(1,post_exp[i]));
            }else{
                string right = st.top(); st.pop();
                string left  = st.top(); st.pop();
                
                string temp = string("(") + left + post_exp[i] + right + ")";
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