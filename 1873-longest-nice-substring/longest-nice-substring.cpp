class Solution {
public:
    bool hasBothCases(unordered_set<char> &st, char c) {
        return st.count(tolower(c)) && st.count(toupper(c));
    }
    string longestNiceSubstring(string s) {
        if(s.size()<2) return "";
        unordered_set<char>st;
        for(auto x:s){
            st.insert(x);
        }

        for(int i=0;i<s.size();i++){
            if(hasBothCases(st,s[i])) continue;

            string left=longestNiceSubstring(s.substr(0,i));
            string right=longestNiceSubstring(s.substr(i+1));

            return left.size()>=right.size()? left:right;
        }
        return s;

    }
};