//Program 01: Print 2D-Array row wise
#include<iostream>
using namespace std;

// Print 2D-Array row wise
void printArray1(int arr[][4],int row,int col){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

// Print 2D-Array column wise
void printArray2(int arr[][4],int row,int col){
    for(int i=0;i<col;i++){
        for(int j=0;j<row;j++){
            cout<<arr[j][i]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    // initialization of 2D array
    int arr[3][4]={
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };

    int row=3;
    int col=4;
    cout<<"Printing row wise"<<endl;
    printArray1(arr,row,col);
    cout<<"Printing column wise"<<endl;
    printArray2(arr,row,col);

    return 0;
}

/*
OUTPUT:
Printing row wise
1 2 3 4 
5 6 7 8 
9 10 11 12 
Printing column wise
1 5 9 
2 6 10 
3 7 11 
4 8 12 
*/