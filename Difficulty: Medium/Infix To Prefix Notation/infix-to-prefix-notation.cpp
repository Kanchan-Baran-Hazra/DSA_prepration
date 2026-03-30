class Solution {
public:
    static int precedence(char c){
        if(c=='+' || c=='-') return 1;
        else if(c=='*' || c=='/') return 2;
        else if(c=='^') return 3;
        return -1;
    }

    string infixToPrefix(string &s) {
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
};
