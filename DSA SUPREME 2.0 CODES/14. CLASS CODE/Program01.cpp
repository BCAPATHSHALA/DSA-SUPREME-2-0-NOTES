// Program 01: Length of string
#include<iostream>
#include <cstring>
using namespace std;

// find length of string
int findLength(char ch[],int size){
    int length = 0;

    for(int i = 0; i < size; i++){
        if(ch[i] == '\0'){
            break;
        }
        else{
            length++;
        }
    }
    return length;
}

// find length of string with the help of while loop
int findLengthByWhileLopp(char ch[],int size){
    int index = 0;

    while(ch[index]!='\0'){
        index++;
    }
    return index;
}

int main(){
    char ch[100];

    cin>>ch;

    int lengthA = findLength(ch, 100);
    int lengthB = findLengthByWhileLopp(ch, 100);

    cout<<"Length of string via our method: "<<lengthA<<endl;
    cout<<"Length of string via builtin method: "<<strlen(ch)<<endl;
    cout<<"Length of string via our method: "<<lengthB<<endl;

    return 0;
}

/*
Time Complexity: O(N), where N is length of char array
Space Complexity: O(1)
*/

/*
INPUT: MyNameIsBabbar
OUTPUT: 
Length of string via our method: 14
Length of string via builtin method: 14
Length of string via our method: 14
*/