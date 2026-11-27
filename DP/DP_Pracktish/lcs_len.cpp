#include <bits/stdc++.h>
using namespace std;

int helper(string &s1,string &s2,int i,int j,vector<vector<int>>& dp){
    if(i<0 || j<0) return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    if(s1[i]==s2[j]) return dp[i][j]= 1+helper(s1,s2,i-1,j-1,dp);

    return dp[i][j]= max(helper(s1,s2,i-1,j,dp),helper(s1,s2,i,j-1,dp));
}

int helper_tab(string &s1,string &s2,int n,int m,string &str){
    vector<vector<int>> dp(n+1,vector<int>(m+1));

    for(int i=0;i<n;i++) dp[i][0]=0;
    for(int j=0;j<m;j++) dp[0][j]=0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]) dp[i][j]= 1+dp[i-1][j-1];

            else dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
        }
    }

    int i=n;
    int j=m;
    while(i>0 && j>0){
        if(s1[i-1]==s2[j-1]){
            str.push_back(s1[i-1]);
            i--;
            j--;
        }else if(dp[i-1][j]>dp[i][j-1]){
            i--;
        }else{
            j--;
        }
    }
    return dp[n][m];
}

void lcs_len(string s1,string s2){
    int n=s1.size();
    int m=s2.size();
    vector<vector<int>> dp(n,vector<int>(m,-1));
    // return helper(s1,s2,n-1,m-1,dp);
    string lcs_str="";
    cout<< helper_tab(s1,s2,n,m,lcs_str);
    reverse(lcs_str.begin(),lcs_str.end());
    cout<<"\n"<<lcs_str<<endl;
}

int main(){
    // cout<<"hello";
    lcs_len("abcde","bdgek");
    return 0;
}