// PROBLEM 6: Transpose of a matrix
#include<iostream>
#include<limits.h>
using namespace std;

void printTranspose(int nums[][3], int row, int col){
    for (int i = 0; i < row; i++)
    {
        for (int j = i; j < col; j++)
        {
            swap(nums[i][j], nums[j][i]);           
        }       
    }

    cout<<"Transpose Matrix"<<endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout<<nums[i][j]<<" ";         
        } 
        cout<<endl;      
    }
}

int main(){
    int nums[3][3];
    int row = 3;
    int col = 3;

    cout<<"Enter element of nums"<<endl;
    for (int i = 0; i < row; i++)
    {
        cout<<"ROW "<<i<<endl;
        for (int j = 0; j < col; j++)
        {
            cin>>nums[i][j];
        }       
    }

    printTranspose(nums, row, col);
    return 0;    
}

/*
Enter element of nums
ROW 0
1 2 3
ROW 1
4 5 6
ROW 2
7 8 9
Transpose Matrix
1 4 7
2 5 8
3 6 9
*/