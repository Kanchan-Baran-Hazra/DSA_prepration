// Cycle detection using DFS

#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:
    int V;
    vector<vector<int>> edges;

    Graph(int V){
        this->V = V;
        edges.resize(V);
    }

    void addEdge(int u,int v){
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    void print(){
        for(int i=0;i<V;i++){
            cout<<i<<":";
            for(int j=0;j<edges[i].size();j++){
                cout<<edges[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    bool helper(int src,int parr,vector<bool>& mark){
        mark[src]=true;

        for(int i=0;i<edges[src].size();i++){
            if(!mark[edges[src][i]]){
                return helper(edges[src][i],src,mark);
            }else if(edges[src][i]!=parr) return true;
        }
        return false;
    }

    void isCycle(){
        vector<bool> mark(V,false);
        cout<<helper(0,-1,mark);
    }
};

int main(){
    // cout<<"hello";
    Graph g(5);

    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(4,1);
    // g.print();
    g.isCycle();
    return 0;
}