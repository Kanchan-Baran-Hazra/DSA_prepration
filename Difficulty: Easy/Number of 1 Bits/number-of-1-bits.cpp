class Solution {
  public:
    int setBits(int n) {
        // Write Your Code here
        string temp="";
        
        while(n>0){
            int x=n%2;
            char c = x + '0';
            temp.push_back(c);
            n/=2;
        }
        
        int ans=0;
        
        for(int i=0;i<temp.size();i++){
            if(temp[i]=='1') ans++;
        }
        
        return ans;
    }
};