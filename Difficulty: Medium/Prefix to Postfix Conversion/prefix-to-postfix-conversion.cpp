// User function Template for C++

class Solution {
  public:
    static int precedence(char c){
        if(c=='+' || c=='-') return 1;
        else if(c=='*' || c=='/') return 2;
        else if(c=='^') return 3;
        return -1;
    }
    
    static string infixToPostfix(string& s) {
        // code here
        stack<char>st;
        string ans="";
        
        for(int i=0;i<s.size();i++){
            if(isalnum(s[i])){
                ans.push_back(s[i]);
            }else if(s[i]=='('){
                st.push(s[i]);
            }else if(s[i]==')'){
                while(st.size()!=0 && st.top()!='('){
                    ans.push_back(st.top());
                    st.pop();
                }
                if(st.size()!=0) st.pop();
            }else{
                while(st.size()!=0 && (precedence(st.top())>precedence(s[i]) ||
                precedence(st.top())==precedence(s[i]) && s[i]!='^')){
                    ans.push_back(st.top());
                    st.pop();
                }
                st.push(s[i]);
            }
        }
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
    }
    string preToPost(string pre_exp) {
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
        
        return infixToPostfix(ans);
    }
};