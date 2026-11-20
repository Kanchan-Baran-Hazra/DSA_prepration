#include<bits/stdc++.h>
using namespace std;

int helper(int i,vector<int>& cost){
    if(i>=cost.size()) return 0;

    int take1=cost[i]+helper(i+1,cost);
    int take2=INT_MAX;
    if(i+2<cost.size())
    take2=cost[i]+helper(i+2,cost);

    return min(take1,take2);
}

int climbing_cost(){
    vector<int> cost={10,15,20};
    int st1=helper(0,cost);
    int st2=helper(1,cost);

    return min(st1,st2);
}

int main(){
    cout<<climbing_cost();
    return 0;
}