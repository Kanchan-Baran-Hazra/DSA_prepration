class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int ans=0;
        for(int i=num1;i<=num2;i++){
            string s=to_string(i);
            int count=0;
            for(int j=1;j<s.size()-1;j++){
                int x=s[j-1]-'0';
                int y=s[j]-'0';
                int z=s[j+1]-'0';

                if(x<y && y>z || x>y && y<z) count++;
            }
            ans+=count;
        }
        return ans;
    }
};