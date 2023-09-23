// Program 05: Check palindrome
#include<iostream>
#include <cstring>
using namespace std;

// Check palindrome
bool checkPalindrome(char ch[],int size){
    int s = 0;
    int e = size-1;

    while(s<=e){
        if(ch[s]!=ch[e]){
            return false;
        }
        s++;
        e--;
    }
    return true;
}

int main(){
    char ch[100];

    cin.getline(ch,100);

    int length = strlen(ch);
    bool ans = checkPalindrome(ch,length);
    
    if(ans){
        cout<<"Valid"<<endl;
    }
    else{
        cout<<"Invalid"<<endl;
    }

    return 0;
}

/*
Time Complexity: O(N/2)=O(N), where N is length of char array
Space Complexity: O(1)
*/

/*
INPUT: RACECAR
OUTPUT: Valid

INPUT: BABBAR
OUTPUT: Invalid
*/