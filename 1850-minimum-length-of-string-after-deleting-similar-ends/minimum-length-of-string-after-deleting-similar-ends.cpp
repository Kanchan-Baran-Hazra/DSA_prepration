class Solution {
public:
    int minimumLength(string s) {
        int i=0;
        int j=s.size()-1;
        while(i<j){
            if(s[i]!=s[j]) return j-i+1;
            else{
                char com=s[i];
                while(i<=j && s[i]==com) i++;
                while(i<=j && s[j]==com) j--;
            }
        }
        if(i>j)
        return 0;
        return i-j+1;
    }
};