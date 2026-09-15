// cource schedule II

#include <bits/stdc++.h>
using namespace std;

bool helper(int x,vector<bool>& mark,vector<bool>& rec,stack<int>& st,vector<vector<int>>& temp){
    mark[x]=true;
    rec[x]=true;
    cout<<"Visited :"<<x<<endl;

    for(int i=0;i<temp.size();i++){
        if(temp[i][1]==x){
            if(!mark[temp[i][0]]){
                if(!helper(temp[i][0],mark,rec,st,temp)) return false;
            }else if(rec[temp[i][0]]) return false;
        }
    }
    rec[x]=false;
    st.push(x);
    return true;
}


void courceSchedule(int n,vector<vector<int>>& temp){
    vector<bool> mark(n,false);
    vector<bool> rec(n,false);
    stack<int>st;

    if(helper(0,mark,rec,st,temp)){
        while(st.size()!=0){
            cout<<st.top()<<endl;
            st.pop();
        }
    }else{
        cout<<"Not possible"<<endl;
    }
    
}

int main(){
    // cout<<"hello";
    vector<vector<int>> temp={{1,0},{2,0},{3,1},{3,2},{4,1},{4,3}};
    int x=5;
    courceSchedule(x,temp);
    return 0;
}