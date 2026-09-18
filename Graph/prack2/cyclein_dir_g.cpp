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
        // edge[v].push_back(u);
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

    bool helper(int x,vector<bool>& mark,vector<bool>& re_stack){
        mark[x]=true;
        re_stack[x]=true;

        for(int i=0;i<edge[x].size();i++){
            if(!mark[edge[x][i]]){
                if(helper(edge[x][i],mark,re_stack)) return true;
            }else if(re_stack[edge[x][i]]){
                return true;
            }
        }

        re_stack[x]=false;
        return false;
    }

    bool is_cycle(){
        vector<bool> re_stack(V,false);
        vector<bool> mark(V,false);

        return helper(0,mark,re_stack);
    }
};

int main(){
    // cout<<"hello"<<endl;
    Graph g(5);

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    // g.addEdge(3,4);
    g.addEdge(2,4);
    g.addEdge(4,1);

    g.print();
    cout<<g.is_cycle();

    return 0;
}