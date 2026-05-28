class Solution {
public:
    bool rotateString(string s, string goal) {
        unordered_map<char,int>mp1;
        unordered_map<char,int>mp2;
        for(int i=0;i<s.size();i++){
            mp1[s[i]]++;
        }

        for(int i=0;i<goal.size();i++){
            mp2[goal[i]]++;
        }
        s+=s;
        if(s.find(goal) != string::npos && mp1==mp2){
            return true;
        }

        return false;
    }
};