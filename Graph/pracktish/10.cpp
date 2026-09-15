// cource schedule I

#include <bits/stdc++.h>
using namespace std;

bool helper(int x,vector<bool>& mark,vector<bool>& st,vector<vector<int>>& edge){
    mark[x]=true;
    st[x]=true;

    for(int i=0;i<edge.size();i++){
        if(edge[i][1]==x){
            if(!mark[edge[i][0]]){
                if(!helper(edge[i][0],mark,st,edge)) return false;
            }else if(st[edge[i][0]]) return false;
        }
    }

    st[x]=false;
    return true;
}

bool ispossible(int n,vector<vector<int>>& edge){
    vector<bool>mark(n,false);
    vector<bool>st(n,false);
    return helper(0,mark,st,edge);
}

int main(){
    // cout<<"helo";
    vector<vector<int>> temp={{1,0},{2,1},{3,2},{3,0}};   //{{1,0},{2,1},{3,2},{3,0},{1,3}};------>false
    // vector<int>temp1;
    // temp1.push_back(1);
    // temp1.push_back(0);

    // vector<int>temp2;
    // temp2.push_back(2);
    // temp2.push_back(0);

    // vector<int>temp3;
    // temp3.push_back(3);
    // temp3.push_back(1);

    // vector<int>temp4;
    // temp4.push_back(3);
    // temp4.push_back(2);

    // temp.push_back(temp1);
    // temp.push_back(temp2);
    // temp.push_back(temp3);
    // temp.push_back(temp4);-------->true

    cout<<ispossible(4,temp);
    return 0;
}