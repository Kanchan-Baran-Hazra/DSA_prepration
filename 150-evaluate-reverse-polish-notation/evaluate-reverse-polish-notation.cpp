class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long>st;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/"){
                int second=st.top();
                st.pop();
                int first=st.top();
                st.pop();
                if(tokens[i][0]=='+'){
                    st.push(first+second);
                }else if(tokens[i][0]=='-'){
                    st.push(first-second);
                }else if(tokens[i][0]=='*'){
                    st.push(first*second);
                }else{
                    st.push(first/second);
                }
            }else{
                st.push(stoll(tokens[i]));
            }
        }

        return st.top();
    }
};