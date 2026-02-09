class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            st.push(s[i]);
            if(st.top()=='c'){
                int count=3;
                string ans="";
                while(st.size()!=0 && count!=0){
                    ans.push_back(st.top());
                    st.pop();
                    count--;
                }
                if(ans!="cba"){
                    for(int k=0;k<ans.size();k++){
                        st.push(ans[k]);
                    }
                }
            }
        }
        return st.size()==0;
    }
};