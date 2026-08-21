#include <bits/stdc++.h>
using namespace std;

bool issqure(long long x){
    long long root=sqrt(x);

    return root*root==x;
}

int count_good(vector<int> &node,vector<int> &value,int n,int i){
    if(i>=n) return 0;
    
    int x=2*i+1;
    int y=2*i+2;
    int count1=count_good(node,value,n,x);
    int count2=count_good(node,value,n,y);
    vector<int>temp;
    int count=0;
    temp.push_back(value[i]);
    if(x<n) temp.push_back(value[x]);
    if(y<n) temp.push_back(value[y]);
    if(temp.size()>1){
        for(int k=0;k<temp.size()-1;k++){
            for(int s=k+1;s<temp.size();s++){
                if(issqure(temp[k]*temp[s])) count++;
            }
        }
    }

    return count1+count2+count;
}


int main(){
    vector<int>node={1,2,3,4,5};
    vector<int>value={6,2,3,8,18};

    cout<<count_good(node,value,5,0);
    return 0;
}