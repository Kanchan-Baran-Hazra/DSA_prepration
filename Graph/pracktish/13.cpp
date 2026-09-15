// Topological Sorting using Kahn's Algorithm

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

    void kansAlgo(){
        vector<int> indg(V,0);

        for(int i=0;i<V;i++){
            for(int j=0;j<edge[i].size();j++){
                indg[edge[i][j]]++;
            }
        }

        queue<int>q;

        for(int i=0;i<indg.size();i++){
            if(indg[i]==0) q.push(i);
        }

        vector<int>ans;

        while(q.size()!=0){
            int x=q.front();
            q.pop();
            ans.push_back(x);

            for(int i=0;i<edge[x].size();i++){
                indg[edge[x][i]]--;
                if(indg[edge[x][i]]==0) q.push(edge[x][i]);
            }
        }

        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<endl;
        }
    }
};

int main(){
    // cout<<"helo";
    Graph g(6);

    // g.addedge(1,0);
    // g.addedge(2,0);
    // g.addedge(1,3);
    // g.addedge(3,4);
    // g.addedge(2,5);
    // g.addedge(5,4);

    g.addedge(5,0);
    g.addedge(4,0);
    g.addedge(2,3);
    g.addedge(3,1);
    g.addedge(5,2);
    g.addedge(4,1);

    // g.print();
    g.kansAlgo();
    
    return 0;
}