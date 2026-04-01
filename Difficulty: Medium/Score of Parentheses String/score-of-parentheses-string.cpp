class Solution {
  public:
    int scoreOfParentheses(string& s) {
        // code here
        int depth=0;
        int ans=0;
        char prev='(';
        
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                depth++;
            }else{
                depth--;
                if(prev=='('){
                    ans+=pow(2,depth);
                }
            }
            prev=s[i];
        }
        
        return ans;
    }
};