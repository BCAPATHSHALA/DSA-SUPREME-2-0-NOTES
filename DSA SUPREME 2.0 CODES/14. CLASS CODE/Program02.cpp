// Program 02: Reverse string
#include<iostream>
#include <cstring>
using namespace std;

// Step 01: Find length of string 
int findLength(char ch[],int size){
    int index = 0;

    while(ch[index]!='\0'){
        index++;
    }
    return index;
}

// Step 02: Reverse string with two pointer approach
void reverseString(char ch[],int size){
    int s = 0;
    int e = size-1;

    while(s<=e){
        swap(ch[s],ch[e]);
        s++;
        e--;
    }
}

int main(){
    char ch[100];

    cin>>ch;

    int length = findLength(ch,100);
    reverseString(ch,length);
    cout<<"After reversing string: "<<ch<<endl;

    return 0;
}
/*
Time Complexity: O(N), where N is length of char array
Space Complexity: O(1)
*/
/*
INPUT: MANOJ
OUTPUT: After reversing string: JONAM
*/