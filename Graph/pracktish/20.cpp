// Min cost to connect all data points
#include <bits/stdc++.h>
using namespace std;

int getDist(vector<vector<int>>& points,int p1,int p2){

    int dist=abs(points[p1][0]-points[p2][0])+abs(points[p1][1]-points[p2][1]);
    return dist;
}

int minCost(vector<vector<int>>& points){
    int n=points.size();
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
    vector<bool> visited(n,false);
    int mini=0;

    pq.push({0,0});   // cots,index;
    while (pq.size()!=0)
    {
        pair<int,int> x=pq.top();
        pq.pop();

        int cost=x.first;
        int idx=x.second;
        if(visited[idx]) continue;
        
        visited[idx]=true;
        mini+=cost;

        for(int i=0;i<n;i++){
            int dist=getDist(points,idx,i);
            pq.push({dist,i});
        }
    }

    return mini;
}

int main(){
    // cout<<"hello";
    vector<vector<int>> points={{0,0},{2,2},{3,10},{5,2},{7,0}};
    cout<<minCost(points);
    return 0;
}