// PROBLEM 3: Reverse an array (Two Pointers Approach)
#include<iostream>
#include<utility>
using namespace std;

void reverseNums(int nums[], int size ){
    int start = 0;
    int end = size - 1;
    
    while (start <= end)
    {
        swap(nums[start++], nums[end--]);
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

    reverseNums(nums, size);
    return 0;    
}

/*
Enter the size of nums
5
Enter the elements of nums
10
20
30
40
50
50 40 30 20 10
*/