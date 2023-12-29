// Basic problems on maps


// PROBLEM 1: Store all character frequency of a string
#include<iostream>
#include<unordered_map>
using namespace std;

void countCharacter(unordered_map<char, int> &mapping, string str){
    for(int i=0; i<str.length(); i++){
        char ch = str[i];
        mapping[ch]++;
    }
}

int main(){
    string str = "lovebabbar";
    unordered_map<char, int> mapping;
    countCharacter(mapping, str);

    for(auto i: mapping){
        cout << i.first << " -> " << i.second << endl;
    }

    return 0;
}
