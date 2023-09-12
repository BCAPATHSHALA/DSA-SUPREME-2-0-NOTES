//Program 04: Print row wise and column wise sum of 2D-Array
#include<iostream>
#include<limits.h>
using namespace std;

// Print row wise sum
void printRowWiseSum(int arr[][3],int row,int col){
    
    for(int i=0;i<row;i++){
        int sum=0;
        for(int j=0;j<col;j++){
            sum+=arr[i][j];
        }
        cout<<sum<<endl;
    }
}

// Print column wise sum
void printCulumnWiseSum(int arr[][3],int row,int col){
    
    for(int i=0;i<col;i++){
        int sum=0;
        for(int j=0;j<row;j++){
            sum+=arr[j][i];
        }
        cout<<sum<<endl;
    }
}

int main(){
    // initialization of 2D array
    int arr[3][3]={
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    int row=3;
    int col=3;

    cout<<"Row wise sum"<<endl;
    printRowWiseSum(arr,row,col);
    cout<<"Column wise sum"<<endl;
    printCulumnWiseSum(arr,row,col);

    return 0;
}

/*
Row wise sum
6
15
24
Column wise sum
12
15
18
*/