class Solution {
public:
    string makeGood(string s) {
        stack<char>st;

        for(int i=0;i<s.size();i++){
            if(st.size()==0 || int(st.top())!=int(s[i]+32) && int(st.top())+32!=int(s[i])){
                st.push(s[i]);
            }else{
                st.pop();
            }
        }
        string ans="";
        while(st.size()!=0){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};