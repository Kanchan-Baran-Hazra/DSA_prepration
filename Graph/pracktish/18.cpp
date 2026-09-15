// Kruskal algorithm
#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int u, v, wt;
    Edge(int u, int v, int wt)
    {
        this->u = u;
        this->v = v;
        this->wt = wt;
    }
};

class Graph
{
public:
    int V;
    vector<Edge> edg;
    vector<int> par, rank;
    int count = 0;

    Graph(int x)
    {
        this->V = x;
        for (int i = 0; i < x; i++)
        {
            par.push_back(i);
            rank.push_back(0);
        }
    }

    void addedge(int u, int v, int wt)
    {
        edg.push_back(Edge(u, v, wt));
    }

    static bool comp(Edge x, Edge y)
    {
        return x.wt <= y.wt;
    }

    void sortt()
    {
        sort(edg.begin(), edg.end(), comp);
    }

    void union_byRank(int a, int b)
    {
        int parA = getPar(a);
        int parB = getPar(b);

        if (parA == parB)
            return;
        else if (rank[parA] == rank[parB])
        {
            par[parB] = parA;
            rank[parA]++;
        }
        else if (rank[parA] < rank[parB])
        {
            par[parA] = parB;
        }
        else
        {
            par[parB] = parA;
        }
    }

    int getPar(int x)
    {
        if (par[x] == x)
            return x;

        return par[x] = getPar(par[x]);
    }

    void kruskal_algo()
    {
        for (int i = 0; i < edg.size(); i++)
        {
            Edge node = edg[i];

            if (getPar(node.u) == getPar(node.v))
                continue;
            else
            {
                count += node.wt;
                union_byRank(node.u, node.v);
            }
        }
    }

    void get_count()
    {
        cout << "Total minimal cost:" << count << endl;
    }
};

int main()
{
    // cout<<"hello";
    Graph g(4);
    g.addedge(0, 1, 10);
    g.addedge(1, 0, 10);

    g.addedge(1, 3, 40);
    g.addedge(3, 1, 40);

    g.addedge(0, 3, 30);
    g.addedge(3, 0, 30);

    g.addedge(0, 2, 15);
    g.addedge(2, 0, 15);

    g.addedge(3, 2, 50);
    g.addedge(2, 3, 50);

    g.sortt();
    g.kruskal_algo();
    g.get_count();
    return 0;
}

// // gemini ansss
// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// class Edge {
// public:
//     int u, v, wt;
//     Edge(int u, int v, int wt) {
//         this->u = u;
//         this->v = v;
//         this->wt = wt;
//     }
// };

// class Graph {
// public:
//     int V;
//     vector<Edge> edg;
//     vector<int> par, rank;
//     int count = 0;

//     Graph(int x) {
//         this->V = x;
//         for (int i = 0; i < x; i++) {
//             par.push_back(i);
//             rank.push_back(0);
//         }
//     }

//     void addedge(int u, int v, int wt) {
//         edg.push_back(Edge(u, v, wt));
//     }

//     // Static so std::sort can use it without an object instance
//     static bool comp(const Edge& x, const Edge& y) {
//         return x.wt < y.wt;
//     }

//     void sortt() {
//         sort(edg.begin(), edg.end(), comp);
//     }

//     int getPar(int x) {
//         if (par[x] == x) return x;
//         return par[x] = getPar(par[x]);
//     }

//     void union_byRank(int a, int b) {
//         int parA = getPar(a);
//         int parB = getPar(b);
//         if (parA == parB) return;

//         if (rank[parA] == rank[parB]) {
//             par[parB] = parA;
//             rank[parA]++;
//         } else if (rank[parA] < rank[parB]) {
//             par[parA] = parB;
//         } else {
//             par[parB] = parA;
//         }
//     }

//     void kruskal_algo() {
//         // Iterate through ALL edges, not just V
//         for (int i = 0; i < edg.size(); i++) {
//             Edge node = edg[i];

//             // Use getPar() instead of par[] to check root parents
//             if (getPar(node.u) == getPar(node.v)) {
//                 continue;
//             } else {
//                 count += node.wt;
//                 union_byRank(node.u, node.v);
//             }
//         }
//     }

//     void get_count() {
//         cout << "Total minimal cost: " << count << endl;
//     }
// };

// int main() {
//     Graph g(4);
//     g.addedge(0, 1, 10);
//     // g.addedge(1, 0, 10);
//     g.addedge(1, 3, 40);
//     // g.addedge(3, 1, 40);
//     g.addedge(0, 3, 30);
//     // g.addedge(3, 0, 30);
//     g.addedge(0, 2, 15);
//     // g.addedge(2, 0, 15);
//     // g.addedge(2, 0, 15);

//     g.addedge(3, 2, 50);
//     // g.addedge(2, 3, 50);

//     g.sortt();
//     g.kruskal_algo();
//     g.get_count();
//     return 0;
// }