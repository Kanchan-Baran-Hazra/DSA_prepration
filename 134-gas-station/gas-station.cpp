class Solution {
public:

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int t_cost=0;
        int t_gas=0;
        for(int i=0;i<n;i++){
            t_cost+=cost[i];
            t_gas+=gas[i];
        }
        if(t_cost>t_gas) return -1;

        int total=0;
        int start=0;
        int i=start;

        while(i<n){
            total+=gas[i]-cost[i];
            if(total<0){
                total=0;
                start=i+1;
            }
            i++; 
        }

        return start;
    }
};