// PROBLEM 7: Print all triplets
#include<iostream>
using namespace std;

void printAllTriplets(int nums[], int size){
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            for (int k = 0; k < size; k++)
            {
                cout<<nums[i] <<", "<<nums[j]<<", "<<nums[k]<<endl;
            }
            
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

    printAllTriplets(nums, size);
    return 0;    
}

/*
Enter the size of nums
3
Enter the elements of nums
10 
20
30
10, 10, 10
10, 10, 20
10, 10, 30
10, 20, 10
10, 20, 20
10, 20, 30
10, 30, 10
10, 30, 20
10, 30, 30
20, 10, 10
20, 10, 20
20, 10, 30
20, 20, 10
20, 20, 20
20, 20, 30
20, 30, 10
20, 30, 20
20, 30, 30
30, 10, 10
30, 10, 20
30, 10, 30
30, 20, 10
30, 20, 20
30, 20, 30
30, 30, 10
30, 30, 20
*/