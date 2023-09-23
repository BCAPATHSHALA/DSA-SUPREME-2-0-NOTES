// Program 03: Uppercase to lowercase and vice versa
#include<iostream>
#include <cstring>
using namespace std;

// Lowercase to Uppercase
void convertToUppercase(char ch[],int size){
    int index = 0;

    while(ch[index]!='\0'){
        if(ch[index]>='a' && ch[index]<='z'){
            ch[index]=ch[index]-'a'+'A';
        }
        index++;
    }
}

// Uppercase to Lowercase
void convertToLowercace(char ch[],int size){
    int index = 0;

    while(ch[index]!='\0'){
        if(ch[index]>='A' && ch[index]<='Z'){
            ch[index]=ch[index]-'A'+'a';
        }
        index++;
    }
}

int main(){
    char ch[100];

    cin.getline(ch,100);

    int length = strlen(ch);
    convertToUppercase(ch,length);
    cout<<"After converting to uppercase: "<<ch<<endl;

    convertToLowercace(ch,length);
    cout<<"After converting to lowercase: "<<ch<<endl;

    return 0;
}

/*
Time Complexity: O(N), where N is length of char array
Space Complexity: O(1)
*/

/*
INPUT: My Name Is Manoj
OUTPUT: 
After converting to uppercase: MY NAME IS MANOJ
After converting to lowercase: my name is manoj
*/