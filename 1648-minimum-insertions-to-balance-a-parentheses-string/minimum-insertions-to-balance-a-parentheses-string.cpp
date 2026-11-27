class Solution {
public:
    int minInsertions(string s) {
        int count=0;
        int ans=0;
        int n=s.size();
        int i=0;
        while(i<n){
            if(s[i]=='('){
                count++;
                i++;
            }else{
                if(count>0){
                    count--;
                    if(i+1<n && s[i+1]==')'){
                        i+=2;
                    }else{
                        ans++;
                        i++;
                    }
                }else{
                    ans++;
                    if(i+1<n && s[i+1]==')'){
                        i+=2;
                    }else{
                        ans++;
                        i++;
                    }
                }
            }
        }
        return ans+count*2;
    }
};