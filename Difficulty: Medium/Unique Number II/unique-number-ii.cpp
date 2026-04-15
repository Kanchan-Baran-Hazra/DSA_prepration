class Solution {
  public:
    vector<int> singleNum(vector<int>& arr) {
        // Code here.
        int num=0;
        for(auto it:arr) num^=it;
        
        int r_bit=num & (-num);
        int G0=0;
        int G1=0;
        for(auto it:arr){
            if(r_bit & it) G1^=it;
            else G0^=it;
        }
        
        if(G1>G0) return {G0,G1};
        
        return {G1,G0};
    }
};