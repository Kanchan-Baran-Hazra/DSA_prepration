class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='#'){
                if(st.size()!=0)
                st.pop();
                else continue;
            }else st.push(s[i]);
        }
        s="";
        while(st.size()!=0){
            s.push_back(st.top());
            st.pop();
        }
        for(int i=0;i<t.size();i++){
            if(t[i]=='#'){
                if(st.size()!=0)
                st.pop();
                else continue;
            }else st.push(t[i]);
        }
        t="";
        while(st.size()!=0){
            t.push_back(st.top());
            st.pop();
        }

        return s==t;
    }
};