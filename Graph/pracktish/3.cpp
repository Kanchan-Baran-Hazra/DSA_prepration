#include <bits/stdc++.h>
using namespace std;


class Graph{
    public:
    int V;
    vector<vector<int>>edge;

    Graph(int x){
        this->V=x;
        this->edge.resize(x);
    }

    void addedge(int u,int v){
        this->edge[u].push_back(v);
        this->edge[v].push_back(u);
    }

    void print(){
        for(int i=0;i<edge.size();i++){
            cout<<i<<":";
            for(int j=0;j<edge[i].size();j++){
                cout<<edge[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    void helper(int x,vector<bool>& visited){
        cout<<x<<endl;
        visited[x]=true;

        for(int i=0;i<edge[x].size();i++){
            if(!visited[edge[x][i]]){
                helper(edge[x][i],visited);
            }
        }
    }

    void DFS(){
        vector<bool> visited(V,false);
        helper(0,visited);
    }
};


int main(){
    Graph g(6);

    g.addedge(1,2);
    g.addedge(2,3);
    g.addedge(3,4);
    g.addedge(4,1);
    g.addedge(1,3);
    g.addedge(4,5);
    g.addedge(5,3);
    g.addedge(0,1);

    g.print();

    g.DFS();
    return 0;
}
