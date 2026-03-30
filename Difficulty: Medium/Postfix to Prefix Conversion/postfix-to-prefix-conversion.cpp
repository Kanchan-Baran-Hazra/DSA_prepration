// User function Template for C++

class Solution {
  public:
    static int precedence(char c){
        if(c=='+' || c=='-') return 1;
        else if(c=='*' || c=='/') return 2;
        else if(c=='^') return 3;
        return -1;
    }

    static string infixToPrefix(string &s) {
        stack<char> st;
        string ans = "";

        reverse(s.begin(), s.end());

        // swap brackets
        for(char &c : s){
            if(c == '(') c = ')';
            else if(c == ')') c = '(';
        }

        for(int i = 0; i < s.size(); i++){
            if(isalnum(s[i])){
                ans.push_back(s[i]);
            }
            else if(s[i] == '('){
                st.push(s[i]);
            }
            else if(s[i] == ')'){
                while(!st.empty() && st.top() != '('){
                    ans.push_back(st.top());
                    st.pop();
                }
                if(!st.empty()) st.pop();
            }
            else{
                while(!st.empty() && 
                      (precedence(st.top()) > precedence(s[i]) ||
                      (precedence(st.top()) == precedence(s[i]) && s[i] == '^'))){
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

        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    string postToPre(string post_exp) {
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
        
        return infixToPrefix(ans);
    }
};