#include <bits/stdc++.h>
using namespace std;

class Graph{
    public:
    int V;
    vector<vector<int>>edge;

    Graph(int n){
        this->V=n;
        this->edge.resize(n);
    }

    void addedge(int u,int v){
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    void print(){
        for(int i=0;i<V;i++){
            cout<<i<<":";
            for(int j=0;j<edge[i].size();j++){
                cout<<edge[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};


int main(){
    // cout<<"hello";
    Graph g(3);

    g.addedge(0,1);
    g.addedge(1,2);
    g.addedge(0,2);

    g.print();
    return 0;
}