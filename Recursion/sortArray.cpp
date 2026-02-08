#include <iostream>
#include <vector>
using namespace std;

void helper(vector<int> &arr,int temp){
    if(arr.size()==0 || arr[arr.size()-1]<=temp){
        arr.push_back(temp);
        return;
    }
    int last=arr[arr.size()-1];
    arr.pop_back();
    helper(arr,temp);
    arr.push_back(last);
}

void getSorted(vector<int> &arr){
    if(arr.size()==0) return;
    int last=arr[arr.size()-1];
    arr.pop_back();
    getSorted(arr);
    helper(arr,last);
}

int main(){
    vector<int> arr = {5, 2, 8, 1, 9,1000,70};
    getSorted(arr);
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    return 0;
}