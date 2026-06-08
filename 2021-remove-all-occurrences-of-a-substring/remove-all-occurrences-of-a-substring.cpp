class Solution {
public:
    string removeOccurrences(string s, string part) {
        string temp="";
        for(int i=0;i<s.size();i++){
            temp.push_back(s[i]);
            if(temp.size()>=part.size()){
                string s1=temp.substr(temp.size()-part.size());
                if(s1==part){
                    temp.erase(temp.size()-part.size());
                }
            }
        }

        return temp;
    }
};