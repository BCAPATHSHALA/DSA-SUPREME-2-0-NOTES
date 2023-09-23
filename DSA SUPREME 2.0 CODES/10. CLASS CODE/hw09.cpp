// HW 09: Factorial of A Large Number (GFG)
#include<iostream>
#include<vector>
#include <bits/stdc++.h>
using namespace std;

vector<int> factorial(int N){
    vector<int> ans;
    ans.push_back(1);
    int carry = 0;

    for(int i=2;i<=N;i++){
        for(int j=0;j<ans.size();j++){
            int x=ans[j]*i+carry;
            // Jo pahle se element rakhe hue hai une me update karta rahunga jab tak j<arr.size() hai
            ans[j]=x%10;
            carry=x/10;
        }
        // Jab tak mera carry equal to zero nahi ho jayega tab tak me ek new element add karta rahunga
        while(carry>0){
            ans.push_back(carry%10);
            carry/=10;
        }
    }

    // Reverse the ans to get the correct value of factorial
    reverse(ans.begin(), ans.end());

    // Returning correct ans
    return ans;
}

int main(){
    int N;
    cout<<"Enter number: ";
    cin>>N;
    
    vector<int> ans = factorial(N);
    for (auto factorialVal : ans) {
        cout<<factorialVal;
    }

    return 0;
}

/*

Factorial of A Large Number (GFG)
Example 01:
Enter number: 5
120


Example 02:
Enter number: 100
93326215443944152681699238856266700490715968264381621
4685929638952175999932299156089414639761565182862536
97920827223758251185210916864000000000000000000000000
*/