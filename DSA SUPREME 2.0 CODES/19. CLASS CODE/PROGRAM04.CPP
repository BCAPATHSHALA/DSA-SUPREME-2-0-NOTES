// ✅PROGRAM 04: Fibonacci series
#include<iostream>
using namespace std;

int fib(int N){
    // Base Case
    if(N == 0){
        return 0;
    }
    if(N == 1){
        return 1;
    }

    // Recusive Calls (Relation)
    int ans = fib(N-1) + fib(N-2);
    return ans;
}

int main(){
    int N = 5;
    cout<<"Nth term is "<<fib(N);

    return 0;
}
