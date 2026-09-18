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

    void topo_sort(){        // kans algorithm
        vector<int> inorder(V,0);
        vector<int> ans;
        
        for(int i=0;i<V;i++){
            for(int j=0;j<edge[i].size();j++){
                inorder[edge[i][j]]++;
            }
        }

        for(int i=0;i<V;i++){
            cout<<inorder[i]<<endl;
        }

        queue<int> q;
        for(int i=0;i<V;i++){
            if(inorder[i]==0){
                q.push(i);
            }
        }

        while (q.size()!=0){
            helper(q,inorder,ans);
        }

        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        
    }

    void helper(queue<int>& q,vector<int>& inorder,vector<int>& ans){
        int el=q.front();
        ans.push_back(el);
        q.pop();

        for(int i=0;i<edge[el].size();i++){
            inorder[edge[el][i]]--;
            if(inorder[edge[el][i]]==0){
                q.push(edge[el][i]);
            }
        }
    }
};

int main(){
    // cout<<"hello"<<endl;
    Graph g(6);

    g.addEdge(5,0);
    g.addEdge(4,0);
    g.addEdge(5,2);
    g.addEdge(4,1);
    g.addEdge(2,3);
    g.addEdge(3,1);

    g.print();

    g.topo_sort();

    return 0;
}