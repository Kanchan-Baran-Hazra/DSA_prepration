class Solution {
public:
    int calculate(string s) {
        stack<int>st;
        char oprator='+';
        int num=0;
        for(int i=0;i<s.size();i++){
            if(isdigit(s[i])){
                num=(num*10)+(s[i]-'0');
            }
            if(!isdigit(s[i]) && s[i]!=' ' || i==s.size()-1){
                if(oprator=='+'){
                    st.push(num);
                }else if(oprator=='-'){
                    st.push(-1*num);
                }else if(oprator=='*'){
                    int top_el=st.top();
                    st.pop();
                    st.push(top_el*num);
                }else if(oprator=='/'){
                    int top_el=st.top();
                    st.pop();
                    st.push(top_el/num);
                }
                num=0;
                oprator=s[i];
            }
        }
        int ans=0;
        while(st.size()>0){
            ans+=st.top();
            st.pop();
        }

        return ans;
    }
};