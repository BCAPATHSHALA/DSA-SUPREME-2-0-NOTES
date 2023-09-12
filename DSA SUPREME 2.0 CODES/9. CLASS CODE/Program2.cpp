//Program 02: Taking input from user in 2D-Array
#include<iostream>
using namespace std;

// Print 2D-Array
void printArray(int arr[][3],int row,int col){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    // initialization of 2D array
    int arr[3][3];
    int row=3;
    int col=3;

    // Taking input from user
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<"Row index = "<<i<<" Column index = "<<j<<endl;
            cin>>arr[i][j];
        }
        cout<<endl;
    }
    
    cout<<"Printing row wise"<<endl;
    printArray(arr,row,col);

    return 0;
}

/*
OUTPUT:
Row index = 0 Column index = 0
1
Row index = 0 Column index = 1
2
Row index = 0 Column index = 2
3
Row index = 1 Column index = 0
4
Row index = 1 Column index = 1
5
Row index = 1 Column index = 2
6
Row index = 2 Column index = 0
7
Row index = 2 Column index = 1
8
Row index = 2 Column index = 2
9
Printing row wise
1 2 3 
4 5 6 
7 8 9 
*/