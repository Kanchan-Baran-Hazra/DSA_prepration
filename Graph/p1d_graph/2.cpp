// vanila BFS implimentation

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

    void BFS(){
        queue<int> q;
        vector<bool> mark(V,false);

        // let the start node is 0
        q.push(0);
        mark[0]=true;

        while(q.size()!=0){
            int x=q.front();
            q.pop();
            cout<<x<<endl;

            for(int i=0;i<edges[x].size();i++){
                if(!mark[edges[x][i]]){
                    q.push(edges[x][i]);
                    mark[edges[x][i]]=true;
                }
            }
        }
        return;
    }


};

int main(){
    // cout<<"hello";
    Graph g(5);

    g.addEdge(0,1);
    g.addEdge(0,4);
    // g.print();

    g.BFS();
    return 0;
}