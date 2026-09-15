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
        edge[v].push_back(u);
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

    void BFS(){
        queue<int> q;
        vector<bool> mark(V,false);
        q.push(1);
        mark[1]=true;

        while (q.size()!=0)
        {
            int x=q.front();
            q.pop();
            cout<<x<<endl;

            for(int i=0;i<edge[x].size();i++){
                if(!mark[edge[x][i]]){
                    q.push(edge[x][i]);
                    mark[edge[x][i]]=true;
                }
            }
        }
    }

    void helper(int x,vector<bool>& mark){
        if(x>=V) return;
        cout<<x<<endl;
        mark[x]=true;

        for(int i=0;i<edge[x].size();i++){
            if(!mark[edge[x][i]]){
                helper(edge[x][i],mark);
            }
        }
    }

    void DFS(){
        vector<bool> mark(V,false);
        helper(1,mark);
    }

};

int main(){
    Graph g(5);

    g.addedge(1,2);
    g.addedge(2,3);
    g.addedge(3,4);
    g.addedge(1,4);

    // g.print();
    // g.BFS();
    g.DFS();

    return 0;
}