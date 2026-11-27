// vanila DFS implimentation

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

    void helper(int src,vector<bool>& mark){
        cout<<src<<endl;
        mark[src] = true;

        for(int i=0;i<edges[src].size();i++){
            if(!mark[edges[src][i]]){
                helper(edges[src][i],mark);
            }
        }
        return;
    }

    void DFS(){
        vector<bool> mark(V,false);
        helper(0,mark);
    }
};

int main(){
    // cout<<"hello";
    Graph g(5);

    g.addEdge(0,1);
    g.addEdge(0,4);
    // g.print();
    g.DFS();
    return 0;
}