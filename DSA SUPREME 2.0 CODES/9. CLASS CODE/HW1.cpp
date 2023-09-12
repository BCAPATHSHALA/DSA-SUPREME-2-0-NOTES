//HW 01: Print column wise sum of 2D-Array
#include<iostream>
#include<limits.h>
using namespace std;

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

    cout<<"Column wise sum"<<endl;
    printCulumnWiseSum(arr,row,col);

    return 0;
}

/*
Column wise sum
12
15
18
*/