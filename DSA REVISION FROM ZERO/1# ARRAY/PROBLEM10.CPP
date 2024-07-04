// PROBLEM 10: Shift array's element by one (left to right)
#include<iostream>
using namespace std;

void shiftArrayElementByOneFromLeftToRight(int nums[], int size){
    int leftMostValue = nums[0];
    for(int i = 0; i < size; i++)
    {
        nums[i] = nums[i+1];
    }

    // Left most value ko (size-1)th index par place karna mat bhoolna
    nums[size-1] = leftMostValue;

    for (int i = 0; i < size; i++)
    {
        cout<<nums[i]<<" ";
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

    shiftArrayElementByOneFromLeftToRight(nums, size);
    return 0;    
}

/*
Enter the size of nums
6
Enter the elements of nums
10
20
30
40
50
60
20 30 40 50 60 10
*/