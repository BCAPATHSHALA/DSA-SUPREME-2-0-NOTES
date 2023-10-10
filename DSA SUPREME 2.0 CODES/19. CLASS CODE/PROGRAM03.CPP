// ✅PROGRAM 03: Pow(2,N)
#include<iostream>
using namespace std;

int pow(int N){
    // Base Case
    if(N == 0){
        return 1;
    }

    // Recusive Calls (Relation)
    int ans = 2 * pow(N-1);

    return ans;
}

int main(){
    int N = 5;
    cout<<pow(N);
    return 0;
}
