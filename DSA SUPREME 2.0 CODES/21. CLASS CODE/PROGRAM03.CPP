// ✅Program 03: Subsequence of string
#include<iostream>
#include<string>
using namespace std;

void findSubsequence(string str, string output, int index){
    // Base Case
    if(index >= str.length()){
        // Ans jo hai output string me build ho chuka hai to print kardo
        cout<<"-> "<<output<<endl;
        return;
    }

    // Processing
    int ch = str[index];

    // Include - Koi ek character ko include kardo Like "A"
    output.push_back(ch);
    findSubsequence(str, output, index + 1);

    // Exclude - Jis character ko include kiya hai ussi character ko 
    // ek bar output me se remove bhi kardo Like "A"
    output.pop_back();
    findSubsequence(str, output, index + 1);
}

int main(){
    string str = "ABC";
    string output = " ";
    int index = 0;

    findSubsequence(str, output, index);
    return 0;
}

/*
AGAR PAHLE EXCLUDE AND BAD ME INCLUDE KAROGE TO OUTPUT YEH AANA CHAIYE
->  
->  C
->  B
->  BC
->  A
->  AC
->  AB
->  ABC
AGAR PAHLE INCLUDE AND BAD ME EXCLUDE KAROGE TO OUTPUT YEH AANA CHAIYE
->  ABC
->  AB
->  AC
->  A
->  BC
->  B
->  C
->  
*/