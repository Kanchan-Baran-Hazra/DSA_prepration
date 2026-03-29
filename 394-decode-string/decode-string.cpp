class Solution {
public:
    static string concatString(string s,int k){
        string ans;
        for(int i=0;i<k;i++){
            ans.append(s);
        }

        return ans;
    }
    string decodeString(string s) {
        stack<string>st1;
        stack<int>st2;

        for(int i=0;i<s.size();i++){
            if(isdigit(s[i])){
                int num = 0;
                while(i < s.size() && isdigit(s[i])){
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                i--;  // adjust index
                st2.push(num);
            }else if(s[i]=='[' || isalpha(s[i])){
                st1.push(string(1,s[i]));
            }else{
                string temp="";
                while(st1.top()!="["){
                    temp=st1.top()+temp;
                    st1.pop();
                }
                st1.pop();
                int rep=st2.top();
                st2.pop();
                st1.push(concatString(temp,rep));
            }
        }
        string ans;
        while(st1.size()>0){
            ans=st1.top()+ans;
            st1.pop();
        }
        return ans;
    }
};