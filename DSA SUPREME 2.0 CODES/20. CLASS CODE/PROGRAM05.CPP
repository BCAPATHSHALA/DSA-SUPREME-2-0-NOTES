// ✅Program 05: Arrays even element stored in vector
#include<iostream>
#include<vector>
using namespace std;

void solve(int arr[], int index, int N, vector<int> &v){
    // Base Case
    if(index >= N){
        return;
    }

    // Processing
    if(arr[index]%2 == 0){
        v.push_back(arr[index]);
    }  

    // Recursive Relation/Call
    solve(arr,index + 1, N, v);
}

int main(){
    int arr[500] = {10,11,12,13,14};
    int size = 5;
    int index = 0;
    vector<int> v;    
    solve(arr,index,size,v);

    for(auto even: v){
        cout<<even<<" ";
    }
    return 0;
}