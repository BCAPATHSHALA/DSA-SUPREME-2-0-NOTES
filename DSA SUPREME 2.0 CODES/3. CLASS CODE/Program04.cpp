// Find the compound interest
#include <bits/stdc++.h>
#include<iostream>
using namespace std;
  
int main()
{
    double p = 10000, r = 5, t = 2;  
    double A = p * (pow((1 + r / 100), t));
    double CI = A - p;  
    cout << "Compound interest is " << CI;  
    return 0;
}

/*
OUTPUT:
Compound interest is 1025
*/