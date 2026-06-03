class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string say=countAndSay(n-1);
        say+="0";
        string ans="";
        int i=0;
        while(i<say.size()-1){
            int count=1;
            while(i<say.size()-1 && say[i]==say[i+1]){
                count++;
                i++;
            }
            ans+=to_string(count);
            ans+=say[i];
            i++;
        }
        return ans;
    }
};