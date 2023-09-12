// Vector for 1D Array
#include<iostream>
#include<vector>
using namespace std;

int main(){

    // Lesson 01: Declare 2D array
    vector<vector<int>> arr1;

    // Lesson 02: Initialization with specific row size and column size that initiate with specific value
    vector<vector<int>> arr2(5,vector<int>(10,0));

    // Lesson 03: Access elements of 2D vector array
    int RowSize=arr2.size(); // 5
    int ColSize=arr2[0].size(); // 10

    for(int i=0;i<RowSize;i++){
        for(int j=0;j<ColSize;j++){
            cout<<arr2[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}

/*
0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 0 0 
*/