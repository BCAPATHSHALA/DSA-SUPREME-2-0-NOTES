// ✅Program 10: Print digits of number
#include<iostream>
#include<vector>
using namespace std;

void printDigits(int &value, vector<int> &v){
    // Base Case
    if(value == 0){
        return;
    }

    // Processing
    int digit = value % 10;
    // update the value
    value = value / 10;   

    // Recursive Relation/Call
    printDigits(value, v);

    // Processing
    v.push_back(digit);
}

int main(){
    int value = 4215;
    vector<int> v;

    printDigits(value, v);
    for(auto digit: v){
        cout<<digit<<" ";
    }    
    return 0;
}