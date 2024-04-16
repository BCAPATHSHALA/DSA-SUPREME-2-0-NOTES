// 2. Reverse a String using Recursion

/*
Example 1:
Input: str = "LOVE"
Output: EVOL

Example 2:
Input: str = "MANOJ"
Output: JONAM

Time and space complexity of this approach is O(N) where N is size of input string.
*/

#include<iostream>
using namespace std;

void solveUsingREC(string &str, int start, int end){
    // Base case
    if(start >= end){
        return;
    }

    // 1 case hum solve kar lenge
    swap(str[start], str[end]);

    // Ab recursion solve kar lega
    solveUsingREC(str, start + 1, end - 1);
}

int main(){
    cout << "Enter input string: ";
    string str;
    cin >> str;

    int start = 0;
    int end = str.size()-1;
    solveUsingREC(str, start, end);
    cout << "Reverse String: " << str << endl;
}