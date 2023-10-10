// ✅PROGRAM 01: Factorial of n number
#include<iostream>
using namespace std;

int factorial(int N){
    // Base Case
    if(N == 1 || N == 0){
        return 1;
    }

    // Recusive Calls (Relation)
    int recursionKaAns = factorial(N-1);

    // Processing
    int finalAns = N * recursionKaAns;
    return finalAns;
}

int main(){
    int N = 5;
    int factorialAns = factorial(N);
    cout<<"Factorial is "<<factorialAns<<endl;

    return 0;
}
