// ✅Permutation of string (Passing string with reference(&str) and using Backtracking Action)
#include<iostream>
#include<string>
using namespace std;

void printPermutation(string &str, int index){
    // Base Case
    if(index >= str.length()){
        cout<< str << " ";
        return;
    }

    for(int j=index; j<str.length(); j++){
        // As a first step ek character ko me khud se swap kr doonga 
        swap(str[index], str[j]);
        // Ab baki ki character swaping recursion sambhal lega
        printPermutation(str, index+1);
        // Backtracking action 
        swap(str[index], str[j]);
    }
}

int main(){
    string str = "abc";
    int index = 0;
    printPermutation(str, index);
    return 0;
}

/*
Example 1:
Input: str = "abc"
Expected Output: abc acb bac bca cba cab 
Your Output: abc acb bac bca cba cab 
*/