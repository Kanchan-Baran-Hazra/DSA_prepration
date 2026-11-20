#include<bits/stdc++.h>
using namespace std;

bool isValid(string s){
    stack<char>st;
    for(int i=0;i<s.size();i++){
        if(s[i]=='(' || s[i]=='{' || s[i]=='[') st.push(s[i]);
        else if(s[i]==')'){
            if(st.size()==0 || st.top()!='(') return false;
            st.pop();
        }
        else if(s[i]=='}'){
            if(st.size()==0 || st.top()!='{') return false;
            st.pop();
        }else{
            if(st.size()==0 || st.top()!='[') return false;
            st.pop();
        }
    }

    return st.size()==0;
}

int main(){
    // cout<<"hello9";
    cout<<isValid("())");
    return 0;
}