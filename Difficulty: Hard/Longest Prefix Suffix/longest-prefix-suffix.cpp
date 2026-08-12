class Solution {
  public:
    int getLPSLength(string &s) {
        // code here
        int maxi=0;
        int i=0;
        int j=1;
        int pos=1;
        while(j<s.size()){
            if(s[i]!=s[j]){
                i=0;
                maxi=0;
                pos++;
                j=pos;
            }
            
            if(s[i]==s[j]){
                maxi++;
                i++;
                j++;
            }
        }
        return maxi;
    }
};