class Solution {
public:
    bool hasAlternatingBits(int n) {
        string temp="";
        
        while(n>0){
            int x=n%2;
            char c = x + '0';
            temp.push_back(c);
            n/=2;
        }
        
        if(temp.size()==1) return true;
        for(int i=1;i<temp.size();i++){
            if(((temp[i-1]-'0') ^ (temp[i]-'0'))==0) return false;
        }
        
        return true;
    }
};