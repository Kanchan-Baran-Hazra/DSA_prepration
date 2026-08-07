class Solution {
public:
    long long countSubstrings(string s, char c) {
        int char_count=0;
        long long ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==c){
                ans+=1;
                ans+=char_count;
                char_count+=1;
            }
        }

        return ans;
    }
};