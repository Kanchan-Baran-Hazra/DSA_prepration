class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n=tokens.size();
        if(n==0) return 0;
        sort(tokens.begin(),tokens.end());
        if(power<tokens[0]) return 0;
        int i=0;
        int j=n-1;
        int score=0;
        int maxi=0;

        while(i<=j){
            if(power>=tokens[i]){
                score++;
                maxi=max(maxi,score);
                power-=tokens[i];
                i++;
            }else{
                if(score<=0) break;
                score--;
                power+=tokens[j];
                j--;
            }
        }

        return maxi;
    }
};