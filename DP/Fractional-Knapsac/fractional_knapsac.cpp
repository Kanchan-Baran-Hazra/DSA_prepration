#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int>& a,pair<int,int>& b){
    double n1=(1.0*a.first)/a.second;
    double n2=(1.0*b.first)/b.second;

    return n1>n2;
}

double frac_knapsac(){
    vector<int> cost={60,100,120,80,150};
    vector<int> wt={10,20,30,40,15};
    int max_knapsac=60;

    vector<pair<int,int>> wt_cost;
    for(int i=0;i<cost.size();i++){
        wt_cost.push_back({cost[i],wt[i]});
    }

    sort(wt_cost.begin(),wt_cost.end(),cmp);
    double ans=0;
    for(int i=0;i<cost.size();i++){
        if(wt_cost[i].second<max_knapsac){
            ans+=wt_cost[i].first;
            max_knapsac-=wt_cost[i].second;
        }else{
            ans+=max_knapsac*((double)wt_cost[i].first/wt_cost[i].second);
            break;
        }
    }

    return ans;
}

int main(){
    // cout<<"hello"<<endl;
    // cout<<frac_knapsac();
    int a=5;
    cout<<a<<endl;
    cout<<a/2<<endl;
    cout<<(1.0*a)/2<<endl;
    cout<<(double)a/2<<endl;
    return 0;
}