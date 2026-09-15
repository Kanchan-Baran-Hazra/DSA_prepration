// Cycle detection using DFS




































// #include <bits/stdc++.h>
// using namespace std;


// class Graph{
//     public:
//     int V;
//     vector<vector<int>>edge;

//     Graph(int n){
//         this->V=n;
//         this->edge.resize(n);
//     }

//     void addedge(int u,int v){
//         edge[u].push_back(v);
//         edge[v].push_back(u);
//     }

//     void print(){
//         for(int i=0;i<V;i++){
//             cout<<i<<":";
//             for(int j=0;j<edge[i].size();j++){
//                 cout<<edge[i][j]<<" ";
//             }
//             cout<<endl;
//         }
//     }

//     bool helper(int x,vector<bool>& visited,int parr){
//         visited[x]=true;

//         for(int i=0;i<edge[x].size();i++){
//             if(!visited[edge[x][i]]){
//                 return helper(edge[x][i],visited,x);
//             }else if(edge[x][i]!=parr) return true;
//         }
//         return false;
//     }

//     void isCycle(){
//         vector<bool>visited(V,false);

//         if(helper(1,visited,0)) cout<<"Cycle detected"<<endl;
//         else cout<<"No cycle ditected"<<endl;
//     }

// };


// int main(){
//     Graph g(5);

//     g.addedge(1,2);
//     // g.addedge(2,3);
//     g.addedge(1,3);

//     g.print();
//     g.isCycle();
//     return 0;
// }