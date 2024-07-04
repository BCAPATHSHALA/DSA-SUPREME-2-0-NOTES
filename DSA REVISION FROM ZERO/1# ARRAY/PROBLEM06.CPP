// PROBLEM 6: Print all pairs
#include<iostream>
using namespace std;

void printAllPairs(int nums[], int size){
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout<<nums[i] <<", "<<nums[j]<<endl;
        }
        
    }    
}

int main(){
    int nums[100];
    int size;

    cout<<"Enter the size of nums"<<endl;
    cin>>size;

    cout<<"Enter the elements of nums"<<endl;
    for (int i = 0; i < size; i++)
    {
        cin>>nums[i];
    }

    printAllPairs(nums, size);
    return 0;    
}

/*
Enter the size of nums
4
Enter the elements of nums
10  
20
30
40
10, 10
10, 20
10, 30
10, 40
20, 10
20, 20
20, 30
20, 40
30, 10
30, 20
30, 30
30, 40
40, 10
40, 20
40, 30
40, 40
*/