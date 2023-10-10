// ✅PROGRAM 05: Return sum from n to 1
#include<iostream>
using namespace std;

int sum(int N){
    // Base Case
    if(N == 1){
        return 1;
    }

    // Recusive Calls (Relation)
    int ans = N + sum(N-1);
    return ans;
}

int main(){
    int sum = 5;
    cout<<"Nth term is "<<sum(N);

    return 0;
}
