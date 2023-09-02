// Pattern 19: Fancy pattern 4
#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    char ch;

    // Outer loop
    for(int row=0; row<n; row = row+1){
        // TODO 1: First
        for(int col=0; col<(row+1); col = col+1){
            int number = col+1;
            ch = number + 'A' - 1;
            cout << ch << " ";
        }
        // TODO 2: Second
        for(char alphabet=ch; alphabet>'A';){
            alphabet = alphabet - 1;
            cout << alphabet << " ";
        }
        // New line
        cout << endl;
    }
    return 0;
}

/*
OUTPUT: when n is 5
A 
A B A 
A B C B A 
A B C D C B A 
A B C D E D C B A 
*/