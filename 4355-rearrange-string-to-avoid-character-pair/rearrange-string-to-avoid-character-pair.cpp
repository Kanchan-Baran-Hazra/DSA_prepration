class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        if(s.size()==1) return s;
        string left="";
        string right="";

        for(int i=0;i<s.size();i++){
            if(s[i]==x) right.push_back(s[i]);
            else left.push_back(s[i]);
        }

        return left+right;
    }
};