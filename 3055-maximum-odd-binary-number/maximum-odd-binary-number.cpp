class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int once=0;
        int zeros=0;

        for(int i=0;i<s.size();i++){
            if(s[i]=='1') once++;
            else zeros++;
        }
        string ans="";
        while(once>1){
            ans.push_back('1');
            once--;
        }
        while(zeros>0){
            ans.push_back('0');
            zeros--;
        }
        ans.push_back('1');
        return ans;
    }
};