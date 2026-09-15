// topo logical sort
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

    void helper(int x,stack<int>& st,vector<bool>& mark){
        mark[x]=true;

        for(int i=0;i<edge[x].size();i++){
            if(!mark[edge[x][i]]){
                helper(edge[x][i],st,mark);
            }
        }

        st.push(x);
        return;
    }


    void topoSort(){
        stack<int>st;
        vector<bool>mark(V,false);
        
        for(int i=0;i<V;i++){
            if(!mark[i])
            helper(i,st,mark);
        }

        while(st.size()!=0){
            cout<<st.top()<<endl;
            st.pop();
        }

        return;
    }
};

int main(){
    // cout<<"hello";
    Graph g(9);

    g.addedge(0,1);
    g.addedge(1,4);
    g.addedge(1,2);
    g.addedge(1,3);
    g.addedge(3,5);
    g.addedge(5,6);
    g.addedge(2,8);
    g.addedge(4,7);
    g.addedge(4,3);

    // g.print();
    g.topoSort();
    return 0;
}