// ✅PROGRAM 02: Reverse counting from n to 1
#include<iostream>
using namespace std;

void print(int N){
    // Base Case
    if(N == 1 || N == 0){
        cout<<N<<" ";
        return;
    }
    // Processing
    cout<<N<<" ";

    // Recusive Calls (Relation)
    print(N-1);
}

int main(){
    int N = 5;
    print(N);

    return 0;
}
