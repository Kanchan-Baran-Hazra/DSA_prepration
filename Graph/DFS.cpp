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

    void BFs(){
        queue<int>Q;
        vector<bool>visited(V,false);

        Q.push(0);
        visited[0]=true;

        while(Q.size()!=0){
            int x=Q.front();
            Q.pop();

            cout<<x<<endl;
            for(int i=0;i<adjList[x].size();i++){
                if(!visited[adjList[x][i]]){
                    Q.push(adjList[x][i]);
                    visited[adjList[x][i]]=true;
                }
            }
        }
    }

    void dfsHelper(int v,vector<bool> &temp){
        cout<<v<<" ";
        temp[v]=true;
        for(int x:adjList[v]){
            if(!temp[x]){
                dfsHelper(x,temp);
            }
        }
    }

    void dfs(){
        vector<bool>temp(V,false);
        
        dfsHelper(0,temp);
    }
};

int main(){
    Graph g(5);

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(3,2);
    g.addEdge(2,4);

    // g.printGraph();
    g.BFs();
    cout<<endl;
    g.dfs();

    return 0;
}