class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char,int>>st;
        vector<int>temp(s.size());
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push({'(',i});
            }else if(s[i]==')'){
                if(st.size()!=0){
                    st.pop();
                }else{
                    temp[i]=1;
                }
            }
        }

        while(st.size()!=0){
            temp[st.top().second]=1;
            st.pop();
        }

        string ans="";
        for(int i=0;i<s.size();i++){
            if((s[i]=='(' || s[i]==')') && temp[i]==1) continue;
            ans.push_back(s[i]);
        }

        return ans;
    }
};