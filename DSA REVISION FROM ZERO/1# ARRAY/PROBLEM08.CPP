// PROBLEM 8: Sort 0's and 1's
#include<iostream>
using namespace std;

void sortZeroAndOne(int nums[], int size){
    int start = 0;
    int end = size - 1;

    while (start < end)
    {
        while (start < end && nums[start] == 0)
        {
            start++;
        }
        while (start < end && nums[end] == 1)
        {
            end --;
        }
        if(start < end && nums[start] == 1 && nums[end] == 0)
        {
            swap(nums[start++], nums[end--]);
        }       
        
    }

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

    sortZeroAndOne(nums, size);
    return 0;    
}

/*
Enter the size of nums
7
Enter the elements of nums
1
0
1
1
0
1
0
0 0 0 1 1 1 1
*/