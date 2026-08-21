#include <bits/stdc++.h>
using namespace std;

class Graph{
    public:
    int V;
    vector<vector<int>>edges;

    Graph(int n){
        this->V=n;
        edges.resize(n);
    }

    void addEdge(int x,int y){
        edges[x].push_back(y);
        edges[y].push_back(x);
    }

    void print(){
        for(int i=0;i<this->V;i++){
            cout<<i<<":";
            for(int j=0;j<this->edges[i].size();j++){
                cout<<this->edges[i][j]<<" ";
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
    g.addEdge(0,2);

    g.print();
    return 0;
}