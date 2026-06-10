#include <iostream>
#include <vector>
using namespace std;

class Graph{
public:
    int V;
    vector<vector<int>> adjList;

    Graph(int V){
        this->V = V;
        adjList.resize(V);
    }

    void addEdge(int u, int v){
        adjList[u].push_back(v);
        adjList[v].push_back(u); // For undirected graph
    }

    bool dfsCycle(int x,vector<bool> &temp,int parent){
        // cout<<x<<" ";
        temp[x]=true;

        for(auto i:adjList[x]){
            if(!temp[i]) return dfsCycle(i,temp,x);
            else{
                if(i!=parent) return true;
            }
        }

        return false;
    }

    bool dfs(){
        vector<bool> temp(V,false);
        return dfsCycle(0,temp,-1);
    }

};

int main(){
    Graph g(5);

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    // g.addEdge(3,2);
    g.addEdge(2,4);

    cout<<g.dfs()<<endl;


    return 0;
}