// Flood Fill Algorithm

#include <bits/stdc++.h>
using namespace std;

void helper(int i,int j,int prev,vector<vector<int>>& temp,int nex){
    if(i<0 || j<0 || i>=temp.size() || j>=temp[0].size() || temp[i][j]!=prev) return;

    temp[i][j]=nex;
    helper(i+1,j,prev,temp,nex);
    helper(i-1,j,prev,temp,nex);
    helper(i,j+1,prev,temp,nex);
    helper(i,j-1,prev,temp,nex);
}

void convert(int n,vector<vector<int>>& temp,int i,int j){
    int prev=temp[i][j];
    helper(i,j,prev,temp,n);
    return;
}

int main(){
    // cout<<"hello";
    vector<vector<int>> temp={{1,1,1},{1,1,0},{1,0,1}};
    int i=1;
    int j=1;
    int changble=5;
    convert(changble,temp,i,j);

    for(int i=0;i<temp.size();i++){
        for(int j=0;j<temp[i].size();j++){
            cout<<temp[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}