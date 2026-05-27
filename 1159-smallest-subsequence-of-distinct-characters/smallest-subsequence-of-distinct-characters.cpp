class Solution {
public:
    string smallestSubsequence(string s) {
        stack<char>st;
        unordered_map<char,int>mp1;
        unordered_map<char,bool>mp2;

        for(int i=0;i<s.size();i++){
            mp1[s[i]]++;
        }

        for(auto x:mp1){
            mp2[x.first]=false;
        }

        for(int i=0;i<s.size();i++){
            if(st.size()==0){
                st.push(s[i]);
                mp1[s[i]]--;
                mp2[s[i]]=true;
            }else if(mp2[s[i]]!=false){
                mp1[s[i]]--;
                continue;
            }else if(mp2[s[i]]==false){
                while(st.size()!=0 && mp1[st.top()]!=0 && st.top()>s[i]){
                    mp2[st.top()]=false;
                    st.pop();
                }
                st.push(s[i]);
                mp1[s[i]]--;
                mp2[s[i]]=true;
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