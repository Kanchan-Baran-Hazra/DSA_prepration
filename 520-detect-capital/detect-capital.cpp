class Solution {
public:
    bool detectCapitalUse(string word) {
        int count=0;
        for(int i=0;i<word.size();i++){
            if(isupper(word[i])) count++;
        }
        if(count==word.size()) return true;
        if(count==0) return true;
        if(isupper(word[0]) && count==1) return true;
        return false;
    }
};