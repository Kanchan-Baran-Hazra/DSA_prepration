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

    bool isCycle(){
        vector<bool> mark(V,false);
        queue<pair<int,int>> q;

        q.push({0,-1});
        mark[0]=true;

        while(q.size()!=0){
            auto x=q.front();
            q.pop();
            int ell=x.first;
            int parr=x.second;

            for(int i=0;i<edges[ell].size();i++){
                if(!mark[edges[ell][i]]){
                    q.push({edges[ell][i],ell});
                    mark[edges[ell][i]]=true;
                }else if(edges[ell][i]!=parr) return true;
            }
        } 
        return false;   
    }
};

int main(){
    // cout<<"hello";
    Graph g(5);

    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(4,1);
    // g.print();

    cout<<g.isCycle();
    return 0;
}