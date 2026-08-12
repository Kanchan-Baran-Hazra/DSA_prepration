class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi=0;
        int i=prices.size()-1;
        int sell=prices[i];
        while(i>=0){
            sell=max(sell,prices[i]);
            maxi=max(maxi,sell-prices[i]);
            i--;
        }
        return maxi;
    }
};