// Print counting from n to 1
#include<iostream>
using namespace std;

int main(){
    int n, counting = 0;
    cout << "Enter a number" << endl;
    cin >> n;
    for(int i = n; i > 0; i = i - 1){
        counting = counting + i;
    }
    cout << "Counting is " << counting << endl;
    return 0;
}

/*
OUTPUT:
Enter a number
3
Counting is 6
*/