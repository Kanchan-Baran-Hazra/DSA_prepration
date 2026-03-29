class Solution {
public:
    int calculate(string s) {
        stack<int>st;
        long long num=0;
        long long result=0;
        int oprator=1;
        for(int i=0;i<s.size();i++){
            if(isdigit(s[i])){
                num=(num*10)+(s[i]-'0');
            }else if(s[i]=='+'){
                result+=(num*oprator);
                oprator=1;
                num=0;
            }else if(s[i]=='-'){
                result+=(num*oprator);
                oprator=-1;
                num=0;
            }else if(s[i]=='('){
                st.push(result);
                st.push(oprator);
                result=0;
                oprator=1;
            }else if(s[i]==')'){
                result+=(num*oprator);
                oprator=1;
                num=0;
                result*=st.top();
                st.pop();
                result+=st.top();
                st.pop();
            }
        }

        return result+(num*oprator);
    }
};