#include <bits/stdc++.h>
using namespace std;


void removedup(vector<int>& dup){
    int i=0;
    int j=0;
    while(j!=dup.size()){
        dup[i]=dup[j];
        while(j!=dup.size() && j==0 || dup[j]==dup[j-1]) j++;
        i++;
    }
    return;
}


int main(){
    // cout<<"hello";
    vector<int> dup={1,1,2,2,3};
    removedup(dup);
    for(int i=0;i<dup.size();i++){
        cout<<dup[i]<<"\n";
    }
    return 0;
}