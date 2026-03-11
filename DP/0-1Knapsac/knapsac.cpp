#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int helper(int W, vector<int> &val, vector<int> &wt,int n){
    vector<vector<int>>t(W+1,vector<int>(n+1,-1));
    for(int i=0;i<=W;i++){
        for(int j=0;j<=n;j++){
            if(i==0 || j==0) t[i][j]=0;
        }
    }

    for(int i=1;i<=W;i++){
        for(int j=1;j<=n;j++){
            if(i<wt[j]){
                t[i][j]=t[i][j-1];
            }else{
                t[i][j]=max((val[j]+t[i-wt[j]][j-1]),t[i][j-1]);
            }
        }
    }
    return t[W][n];
}


int knapsack(int W, vector<int> &val, vector<int> &wt) {
    // code here
    int n=wt.size()-1;
    return helper(W,val,wt,n);
}

int main(){
    int W=5;
    vector<int> val={10,40,30,50};
    vector<int> wt={5,4,2,3};
    cout<<knapsack(W,val,wt)<<endl;

    return 0;
}