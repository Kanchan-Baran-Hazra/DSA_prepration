#include<bits/stdc++.h>
class Solution {
    bool isdup(string s1,string s2){
        unordered_map<char,int>mp;
        for(int i=0;i<s1.size();i++){
            if(mp.find(s1[i])!=mp.end()) return false;
            mp[s1[i]]++;
        }

        for(int i=0;i<s2.size();i++){
            if(mp.find(s2[i])!=mp.end()) return false;
            mp[s2[i]]++;
        }

        return true;
    }

    int helper(vector<string>& arr,int i,int n,string s){
        if(i==n) return 0;
        if(isdup(s,arr[i])){
            return max((int)arr[i].size()+helper(arr,i+1,n,s+arr[i]),helper(arr,i+1,n,s));
        }else{
            return helper(arr,i+1,n,s);
        }
        return 0;
    }
public:
    int maxLength(vector<string>& arr) {
        return helper(arr,0,arr.size(),"");
    }
};