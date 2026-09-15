// Bellman ford algorithm to find shortest path in negetive weights without negetive cycle
#include <bits/stdc++.h>
using namespace std;


class Edge{
    public:
    int val;
    int wt;

    Edge(int val,int wt){
        this->val=val;
        this->wt=wt;
    }

};

void bellman_ford(int src,vector<vector<Edge>>& g){
    int n=g.size();
    vector<int> dist(n,INT_MAX);
    dist[src]=0;

    for(int i=0;i<n;i++){
        for(int u=0;u<n;u++){
            for(Edge v: g[u]){
                if(dist[v.val]>dist[u]+v.wt){
                    dist[v.val]=dist[u]+v.wt;
                }
            }
        }
    }

    for(int i=0;i<dist.size();i++){
        cout<<dist[i]<<" ";
    }
}


int main(){
    // cout<<"hello";
    vector<vector<Edge>> g(5);

    g[0].push_back(Edge(1,2));
    g[0].push_back(Edge(2,4));

    g[1].push_back(Edge(2,-4));
    g[1].push_back(Edge(4,-1));

    g[2].push_back(Edge(3,2));

    g[3].push_back(Edge(3,4));

    bellman_ford(0,g);

    return 0;
}