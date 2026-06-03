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

    void printGraph(){
        for(int i = 0; i < V; i++){
            cout << i << ": ";
            for(int j = 0; j < adjList[i].size(); j++){
                cout << adjList[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main(){
    Graph g(5);

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(3,2);
    g.addEdge(2,4);

    g.printGraph();

    return 0;
}