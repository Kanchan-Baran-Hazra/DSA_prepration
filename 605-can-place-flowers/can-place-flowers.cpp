class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for(int i=0;i<flowerbed.size();i++){
            bool la=i==0 || flowerbed[i-1]==0;
            bool ra=i==flowerbed.size()-1 || flowerbed[i+1]==0;

            if(la && ra && flowerbed[i]==0){
                flowerbed[i]=1;
                n--;
            }
        }
        return n<=0;
    }
};