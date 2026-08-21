#include <bits/stdc++.h>
using namespace std;

class Graph{
    public:
    int V;
    vector<vector<int>>edges;
    Graph(int n){
        this->V=n;
        this->edges.resize(n);
    }

    void addedge(int u,int v){
        this->edges[u].push_back(v);
        this->edges[v].push_back(u);
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

    void BFS(){
        queue<int>q;
        vector<bool>visited(this->V,false);
        q.push(0);
        visited[0]=true;

        while(q.size()!=0){
            int x= q.front();
            q.pop();
            cout<<x<<endl;

            for(int i=0;i<this->edges[x].size();i++){
                if(!visited[this->edges[x][i]]){
                    q.push(this->edges[x][i]);
                    visited[this->edges[x][i]]=true;
                }
            }
        }
    }
};

int main(){

    Graph g(6);
    g.addedge(0,1);
    g.addedge(1,2);
    g.addedge(0,2);
    g.addedge(2,4);
    g.addedge(4,5);
    g.addedge(5,1);

    // g.print();

    g.BFS();
    return 0;
}