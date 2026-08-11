class Solution {
public:
    string reverseWords(string s) {
        stack<string>st;
        s+=" ";
        string sub="";
        for(int i=0;i<s.size();i++){
            if(isspace(s[i]) && sub=="") continue;
            if(isspace(s[i])){
                st.push(sub);
                sub="";
                continue;
            }
            sub.push_back(s[i]);
        }

        string ans="";
        while(st.size()!=0){
            ans+=(st.top());
            st.pop();
            if(st.size()!=0)
            ans+=" ";
        }
        return ans;
    }
};