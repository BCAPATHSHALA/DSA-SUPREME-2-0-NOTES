#include<iostream>
using namespace std;

int main(){
    unsigned int num=-5;

    // shifting bits towards right bit time
    int bit=1;

    // Bitwise right shift
    cout<<(num>>bit); // 2147483645

    return 0;
}

/*
OUTPUT:
2147483645
*/