// PROBLEM 7: Moving All Negative Number to the Left Side of an Array
#include<iostream>
#include<limits.h>
using namespace std;

void moveNegativeToLeft(int nums[], int size){
    int i = 0;
    int j = 0;
    while (i < size)
    {
        if(nums[i] > 0){
            i++;
        }
        else if (nums[i] < 0)
        {
            swap(nums[i], nums[j]);
            i++;
            j++;
        }        
    } 

    cout<<"Nums After Moving Negative"<<endl;
    for (int i = 0; i < size; i++)
    {
        cout<<nums[i]<<" ";
    }       
}

int main()
{
    int nums[100];
    int size;

    cout<<"Enter size of nums"<<endl;
    cin>>size;

    cout<<"Enter element of nums"<<endl;
    for (int i = 0; i < size; i++)
    {
        cin>>nums[i];
    }

    moveNegativeToLeft(nums, size);
    return 0;    
}

/*
Enter size of nums
7
Enter element of nums
-1 2 3 -4 5 -5 -6    
Nums After Moving Negative
-1 -4 -5 -6 5 3 2 
*/