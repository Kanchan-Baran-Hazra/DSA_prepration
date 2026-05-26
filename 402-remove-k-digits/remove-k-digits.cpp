class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k>=num.size()) return "0";
        stack<char>st;
        for(int i=0;i<num.size();i++){
            while(st.size()!=0 && st.top()>num[i] && k>0){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }

        while(k>0){
            st.pop();
            k--;
        }

        string ans="";
        while(st.size()!=0){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        while(ans.size() > 1 && ans[0] == '0') {
            ans.erase(0, 1);
        }

        if(ans.empty())
            return "0";
        

        return ans;
    }
};