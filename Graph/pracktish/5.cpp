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
        edge[v].push_back(u);
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

    bool helper(){
        queue<pair<int,int>>q;
        vector<bool>visited(this->V,false);
        q.push({0,-1});
        visited[0]=true;

        while(q.size()!=0){
            pair<int,int> x=q.front();
            q.pop();

            for(int i=0;i<edge[x.first].size();i++){
                if(!visited[edge[x.first][i]]){
                    q.push({edge[x.first][i],x.first});
                    visited[edge[x.first][i]]=true;
                }else if(x.second!=edge[x.first][i]) return true;
            }
                
        }
        return false;
    }

    void isCycle(){
        if(helper()) cout<<"cycle detected"<<endl;
        else cout<<"cycle not present"<<endl;
    }
};

int main(){
    // cout<<"hello";

    Graph g(5);

    g.addedge(0,1);
    // g.addedge(1,2);
    g.addedge(2,3);
    g.addedge(3,0);
    g.addedge(0,4);

    // g.print();
    g.isCycle();
    return 0;
}