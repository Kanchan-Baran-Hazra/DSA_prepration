class Solution {
  public:
    int myAtoi(string& s) {
        // code here
        long number=0;
        int sing=1;
        for(int i=0;i<s.size();i++){
            if(isalpha(s[i])) return number*sing;
            if(isspace(s[i])) continue;
            if(s[i]=='-'&& number==0){
                sing=-1;
                continue;
            }
            if(s[i]=='+'){
                sing=1;
                continue;
            }
            
            if(isdigit(s[i])){
                number=number*10+(s[i]-'0');
            }
        }
        if(number>INT_MAX && sing==1) return INT_MAX;
        if(number>INT_MAX && sing==-1) return INT_MIN;
        return number*sing;
    }
};