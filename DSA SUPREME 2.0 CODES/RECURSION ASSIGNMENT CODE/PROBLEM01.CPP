// 1. Last occurrence of a char

/*
Example 1:
Input: str = "abcddedg" and target = 'd'
Output: Last Occurrence of d: 6
*/

/*
Approaches:
1. Search from left to right using recursion
2. Search from right to left using recursion
3. Search using STL method strrchr method

Time and space complexity of both approaches 1 and 2 is : O(N) where N is size of input string.
*/

#include<iostream>
#include <string.h>
using namespace std;

// 1. Search from left to right using recursion
void solveUsingRECLtR(string &str, char &target, int &ans, int index){
    // Base Case
    if(index >= str.size()){
        return;
    }
    
    // Ek case hum solve kar lenge
    if(str[index] == target){
        ans = index;
    }

    // Ab Recursion solve kar lega
    solveUsingRECLtR(str, target, ans, index + 1);
}

// 2. Search from right to left using recursion
void solveUsingRECRtL(string &str, char &target, int &ans, int index){
    // Base Case
    if(index < 0){
        return;
    }
    
    // Ek case hum solve kar lenge
    if(str[index] == target){
        ans = index;
        return;
    }

    // Ab Recursion solve kar lega
    solveUsingRECRtL(str, target, ans, index - 1);
}

int main(){
    cout << "Enter input string: ";
    string str;
    cin >> str;

    cout << "Enter input target: ";
    char target ;
    cin >> target;

    cout << "Last Occurrence of " << target << ": ";
    int ans = -1;
    // solveUsingRECLtR(str, target, ans, str.size()-1);
    solveUsingRECRtL(str, target, ans, str.size()-1);
    cout << ans << endl;
}