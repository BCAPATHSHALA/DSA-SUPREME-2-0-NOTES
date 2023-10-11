// ✅Program 09: Return vector with all occurrence of target
#include<iostream>
#include<vector>
using namespace std;

vector<int> searchArray(int arr[], int index, int N, int target){
    vector<int> ans;
    // Base Case
    if(index >= N){
        return ans;
    }

    // Processing
    if(arr[index] == target){
        ans.push_back(index);
    }    

    // Recursive Relation/Call
    vector<int> aageKaAns = searchArray(arr,index + 1, N, target);
    
    // Processing
    for(auto occ: aageKaAns){
        ans.push_back(occ);
    }
}

int main(){
    int arr[500] = {10,20,10,10,30,40};
    int size = 5;
    int index = 0;
    int target = 10;

    vector<int> v = searchArray(arr,index,size,target);
    for(auto occ: v){
        cout<<occ<<" ";
    }
    return 0;
}