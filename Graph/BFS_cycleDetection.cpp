#include <iostream>
#include <vector>
#include <queue>
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

    void printGraph(){
        for(int i = 0; i < V; i++){
            cout << i << ": ";
            for(int j = 0; j < adjList[i].size(); j++){
                cout << adjList[i][j] << " ";
            }
            cout << endl;
        }
    }

    bool BFs(){
        queue<pair<int,int>>Q;
        vector<bool>visited(V,false);

        Q.push({0,-1});
        visited[0]=true;

        while(Q.size()!=0){
            pair<int,int> x=Q.front();
            Q.pop();

            // cout<<x.first<<endl;
            for(int i=0;i<adjList[x.first].size();i++){
                if(!visited[adjList[x.first][i]]){
                    Q.push({adjList[x.first][i],x.first});
                    visited[adjList[x.first][i]]=true;
                }else if(adjList[x.first][i]!=x.second) return false;
            }
        }

        return true;
    }
};

int main(){
    Graph g(5);

    g.addEdge(0,1);
    g.addEdge(1,2);
    // g.addEdge(1,3);
    g.addEdge(3,2);
    g.addEdge(2,4);

    // g.printGraph();
    cout<<g.BFs()<<endl;

    return 0;
}