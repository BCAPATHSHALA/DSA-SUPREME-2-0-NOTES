// CONCEPT 02: Pointer to an array
#include<iostream>
using namespace std;

int main(){
    int num[5] = {10,20,30,40,50};

    // Case 01: Pointer to an array
    int *ptr1 = num; // num ka iska mtlb: "ptr1" point to strating element of array.

    // Case 02: Pointer to an array
    int (*ptr2)[5] = &num; // &num ka iska mtlb: "ptr2" point whole array with strating element of it.

    cout<<ptr2<<endl; // Array ke starting element ka address output me dega: &num[0] = 104
    cout<<ptr2[0]<<endl; // Array ke starting element ka address output me dega: &num[0] = 104
    cout<<*ptr2<<endl; // Array ke starting element ka address output me dega: &num[0] = 104

    cout<<*ptr2[0]<<endl; // Array ke starting element ki value output me dega: num[0] = 1
    cout<<*ptr2<<endl; // Array ke starting element ki value output me dega: num[0] = 1
    cout<<*ptr2[0]<<endl; // Array ke starting element ki value output me dega: num[0] = 1


    cout<<ptr1<<endl; // 104
    cout<<*ptr1<<endl; // 1
    cout<<*ptr1[1]<<endl; // Error because ptr1 is not pointing whole array

    return 0;
}