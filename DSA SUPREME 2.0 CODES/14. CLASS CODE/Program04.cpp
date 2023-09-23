// Program 04: Replace @ with the white space
#include<iostream>
#include <cstring>
using namespace std;

// Replace @ with the white space
void replaceCharacter(char ch[],int size){
    int index = 0;

    while(ch[index]!='\0'){
        if(ch[index]=='@'){
            ch[index]=' ';
        }
        index++;
    }
}

int main(){
    char ch[100];

    cin.getline(ch,100);

    int length = strlen(ch);
    replaceCharacter(ch,length);
    cout<<"After replace to @: "<<ch<<endl;

    return 0;
}

/*
Time Complexity: O(N), where N is length of char array
Space Complexity: O(1)
*/

/*
INPUT: My@Love
OUTPUT: After replace to @: My Love
*/