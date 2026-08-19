class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int rp5=0;
        int rp10=0;
        int rp20=0;

        for(int i=0;i<bills.size();i++){
            if(bills[i]==5) rp5++;
            else if(bills[i]==10){
                rp10++;
                rp5--;
                if(rp5<0) return false;
            }else{
                rp20++;
                if(rp10>0){
                    rp10--;
                    rp5--;
                }else{
                    rp5-=3;
                }

                if(rp5<0 || rp10<0) return false;
            }
        }

        return true;
    }
};