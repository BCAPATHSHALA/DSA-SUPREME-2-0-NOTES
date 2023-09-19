// HW 01: Find sqrt of X upto N decimal place
#include<iostream>
using namespace std;

// Step 01: find integer part of sqrt of X
int integerPart(int x) {
    int s = 0;
    int e = x;
    long long int mid = s+(e-s)/2;
    int ans = -1;

    while(s <= e){
        // kya mid hi to ans nhi hai to return mid
        if(mid*mid == x){
            return mid;
        }
        // agar mid*mid greater then hai x se to left me chale jao
        else if(mid*mid > x){
            e = mid-1;
        }
        // agar mid*mid less then hai x se to ans me mid store karlo and right me chale jao
        else{
            ans = mid;
            s = mid+1;
        }
        mid= s+(e-s)/2;
    }
    return ans;
}

// Step 02: find precision part of sqrt of X
double morePrecision(int x,int precision,int tempSol){
    double ans = tempSol;
    double factor=1;

    for(int i=0;i<precision;i++){
        factor/=10;
        for(double j=ans;j*j<x;j=j+factor){
            ans=j;
            // cout<<"J: "<<j<<" and JxJ: "<<j*j<<" ANS: "<<ans<<endl;
        }
    }
    return ans;
}

int main(){
    int x;
    cin>>x;

    int tempSolution = integerPart(x);
    cout<<"Integer part of square root of X: "<< tempSolution<<endl;

    double finalAns = morePrecision(x,3,tempSolution);
    cout<<"Final square root of X: "<< finalAns<<endl;

    return 0;
}

/*
Example 01:
Input: x = 37
Output: 6.082

Example 02:
Input: x = 36
Output: 6

Example 03:
Input: x = 68
Output: 8.246
*/