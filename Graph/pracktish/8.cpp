// cycle in directed graph
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

    bool helper(int x,vector<bool>& mark,vector<bool>& recpath){
        mark[x]=true;
        recpath[x]=true;

        for(int i=0;i<edge[x].size();i++){
            if(!mark[edge[x][i]]){
                if(helper(edge[x][i],mark,recpath)) return true;
            }else if(recpath[edge[x][i]]) return true;
        }

        recpath[x]=false;
        return false;
    }

    void iscycle(){
        vector<bool> mark(V,false);
        vector<bool> recpath(V,false);
        if(helper(0,mark,recpath)) cout<<"cycle detect";
        else cout<<"cycle not detect";
    }
};

int main(){
    // cout<<"hello";
    Graph g(6);

    g.addedge(0,1);
    g.addedge(1,4);
    g.addedge(1,2);
    g.addedge(1,3);
    g.addedge(3,5);
    g.addedge(3,0);

    // g.print();
    g.iscycle();

    return 0;
}