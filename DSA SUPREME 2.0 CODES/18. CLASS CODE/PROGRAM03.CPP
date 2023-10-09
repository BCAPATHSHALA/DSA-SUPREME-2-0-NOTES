// CONCEPT 03: Pointer with functions
#include<iostream>
using namespace std;

void solve(int *arr, int size){
    cout<<"Inside solve function: "<<endl;
    *arr = *arr + 1; // 11 
    cout<<arr<<endl; // 104
    cout<<&arr<<endl; // 204
    cout<<sizeof(arr)<<endl; // 8
    cout<<endl<<endl;
}

int main(){
    int arr[] = {10,20,30};

    cout<<"Before: "<<endl;
    cout<<arr<<endl; // 104
    cout<<&arr<<endl; // 104
    cout<<sizeof(arr)<<endl; // 12
    for(int i=0; i<3; i++){
        cout<<arr[i]<<" "; // 10, 20, 30
    }
    cout<<endl<<endl;

    solve(arr, 3);

    cout<<"After: "<<endl;
    for(int i=0; i<3; i++){
        cout<<arr[i]<<" "; // 11, 20, 30
    }
    return 0;
}

/*
Before: 
0x7ffe77f5f83c
0x7ffe77f5f83c
12
10 20 30 

Inside solve function: 
0x7ffe77f5f83c
0x7ffe77f5f818
8

After: 
11 20 30 
*/