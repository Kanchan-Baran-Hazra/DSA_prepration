// Prims Algo mimimum spaning tree

#include <bits/stdc++.h>
using namespace std;


int prims_algo(int src,vector<vector<pair<int,int>>>& g){
    int n=g.size();
    int cost=0;
    vector<bool> mark(n,false);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
    pq.push({0,0});

    while (pq.size()!=0){
        pair<int,int> nod=pq.top();
        pq.pop();
        if(!mark[nod.second]) cost+=nod.first;

        mark[nod.second]=true;
        for(int i=0;i<g[nod.second].size();i++){
            int val=g[nod.second][i].first;
            int wt=g[nod.second][i].second;
            if(!mark[val])
            pq.push({wt,val});
        }
    }

    return cost;
    
}



int main(){
    // cout<<"hello";
    vector<vector<pair<int,int>>> g(4);

    g[0].push_back({1,10});
    g[0].push_back({3,30});
    g[0].push_back({2,15});

    g[1].push_back({0,10});
    g[1].push_back({3,40});

    g[2].push_back({0,15});
    g[2].push_back({3,50});

    g[3].push_back({1,40});
    g[3].push_back({2,50});

    cout<<prims_algo(0,g)<<endl;

    return 0;
}