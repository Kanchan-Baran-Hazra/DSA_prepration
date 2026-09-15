#include <bits/stdc++.h>
using namespace std;

class Graph{
    public:
    int V;
    vector<vector<int>> edge;

    Graph(int n){
        this->V=n;
        this->edge.resize(n);
    }

    void addEdge(int u,int v){
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    void print(){
        for(int i=0;i<V;i++){
            cout<<i<<":"<<" ";
            for(int j=0;j<edge[i].size();j++){
                cout<<edge[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};

int main(){
    // cout<<"hello"<<endl;
    Graph g(5);

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,2);

    g.print();

    return 0;
}