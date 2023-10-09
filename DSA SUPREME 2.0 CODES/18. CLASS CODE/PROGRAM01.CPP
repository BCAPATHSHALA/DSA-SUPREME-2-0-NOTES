// CONCEPT 01: Array of pointer
#include<iostream>
using namespace std;

int main(){
    int num[5] = {10,20,30,40,50};

    // Array of pointers: Ek aisa array jiska har ek element apne aap me hi pointer hota hai
    int *arr[5];

    // Assigne address of array &nums[i] to each pointer element of array arr[i]
    arr[0] = &num[0];
    arr[1] = &num[1];
    arr[2] = &num[2];
    arr[3] = &num[3];
    arr[4] = &num[4];

    // Access element of array
    cout<< num << endl;
    cout<< &num << endl;
    cout<< *num << endl;
    cout<< &num[0] << endl;

    cout<< arr << endl;
    cout<< &arr << endl;
    cout<< *arr << endl;
    cout<< &arr[0] << endl;

    cout<< *arr[0] << endl;
    cout<< *arr[1] << endl;
    cout<< *arr[2] + 1 << endl;
    cout<< arr[3] << endl;
    cout<< *(arr[0] + 1) << endl;

    return 0;
}

/*
OUTPUT:
0x7ffed9deea20
0x7ffed9deea20
10

0x7ffed9deea20
0x7ffed9dee9f0
0x7ffed9dee9f0
0x7ffed9deea20

0x7ffed9dee9f0
10
20
31
0x7ffed9deea2c
20
*/