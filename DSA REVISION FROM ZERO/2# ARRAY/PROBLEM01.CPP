// PROBLEM 1: Print 2D Array row and column wise
#include<iostream>
using namespace std;

int main(){
    int nums[100][100];
    int row;
    int col;

    cout<<"Enter raw size: "<<endl;
    cin>>row;
    cout<<"Enter col size: "<<endl;
    cin>>col;

    cout<<"Enter element of nums"<<endl;
    for (int i = 0; i < row; i++)
    {
        cout<<"ROW "<<i<<endl;
        for (int j = 0; j < col; j++)
        {
            cin>>nums[i][j];
        }
        cout<<endl;        
    }

    cout<<"Print element of nums row wise"<<endl;
    for (int i = 0; i < row; i++)
    {
        cout<<"ROW "<<i<<": ";
        for (int j = 0; j < col; j++)
        {
            cout<<nums[i][j]<<" ";
        }       
    }

    cout<<"Print element of nums column wise"<<endl;
    for (int i = 0; i < col; i++)
    {
        cout<<"COL "<<i<<": ";
        for (int j = 0; j < row; j++)
        {
            cout<<nums[j][i]<<" ";
        }
        cout<<endl;        
    }

    return 0;    
}

/*
Enter raw size: 
3
Enter col size:
3
Enter element of nums
ROW 0
1 2 3
ROW 1
4 5 6
ROW 2
7 8 9

Print element of nums row wise
ROW 0: 1 2 3
ROW 1: 4 5 6
ROW 2: 7 8 9
Print element of nums column wise
COL 0: 1 4 7
COL 1: 2 5 8
COL 2: 3 6 9
*/