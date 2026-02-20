class Solution {
public:
    void ispalindrome(string s,int i,int j,int& count){
        while(i>=0 && j<s.size() && s[i]==s[j]){
            count++;
            i--;
            j++;
        }
    }
    int countSubstrings(string s) {
        int count=0;
        for(int i=0;i<s.size();i++){
            ispalindrome(s,i,i,count);
            ispalindrome(s,i,i+1,count);
        }
        return count;
    }
};