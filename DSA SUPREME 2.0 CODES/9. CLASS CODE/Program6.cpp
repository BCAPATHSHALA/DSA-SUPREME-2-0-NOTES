//Program 06: Transpose of a matrix
#include<iostream>
#include<limits.h>
using namespace std;

// Way 01: Transpose of a matrix 
void transposeMatrix1(int arr[][3],int row,int col){

    for(int i=0;i<row;i++){
        for(int j=i;j<col;j++){
           swap(arr[i][j],arr[j][i]);
        }
    }
}

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
    int arr[3][3]={
        {2,4,6},
        {8,3,5},
        {7,9,1}
    };
    int row=3;
    int col=3;

    cout<<"Way 01: Transpose of a matrix"<<endl;
    transposeMatrix1(arr,row,col);
    printArray(arr,row,col);

    return 0;
}

/*
Way 01: Transpose of a matrix
2 8 7 
4 3 9 
6 5 1 
*/