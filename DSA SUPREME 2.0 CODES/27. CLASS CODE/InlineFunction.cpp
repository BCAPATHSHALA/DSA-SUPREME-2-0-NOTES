// 📂 3. Inline function in C++
/*
1. An inline function is a regular function that is defined by the inline keyword.
2. The code for an inline function is inserted directly into the code of the calling function by compiler 
while compiling, which can result in faster execution and less overhead compared to regular function calls.
3. Instead of calling function the statements of functions are pasted in calling function.
4. Used with small sized functions. So that executables are small 
(handled automatically by compiler optimisation levels).
*/

#include<iostream>
using namespace std;

inline void dispalyNum(int num){
    cout<<num<<endl;
}

int main(){
    dispalyNum(5);
    dispalyNum(8);
    dispalyNum(666);
    return 0;
}