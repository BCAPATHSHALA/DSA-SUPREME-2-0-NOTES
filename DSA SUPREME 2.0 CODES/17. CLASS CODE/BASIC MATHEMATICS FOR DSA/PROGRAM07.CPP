// PROGRAM 07: find Prime Numbers Between given Interval[Left,Right] using Segmented Sieve 
#include<iostream>
#include<vector>
#include <cmath>
using namespace std;


// ✅Optimising Sieve of Eratoshenes
vector<bool> Sieve(int N){

    vector<bool> sieve(N+1,true);
    sieve[0]=sieve[1]=false;

    for(int i=2; i*i<=N ; i++){ 
        if(sieve[i]){
            for(int j=i*i; j<=N; j+=i){ 
                sieve[j]=false;
            }
        }
    }    
    return sieve;
}

// ✅Segmented Sieve
vector<bool> segSieve(int L, int R){
    vector<bool> sieve = Sieve(R); 
    // Step 01: Normal sieve i: 0  1  2  3  4  5  6  7  8  9  10  11  12  13  14  15  16  17  18  19  20  21  22  23  24  25  26  27  28  29  30 = true and false
    //               sieve[i]:  F  F  T  T  F  T  F T  F   F  F   F   F   T   F   F   F   T   F   T   F   F   F   T   F   F   F   F   F   T   F
    
    vector<int> basePrime; 
    for(int i=0; i<sieve.size(); i++){
        if(sieve[i]){
            basePrime.push_back(i);
        }
    }
    // Step 02: find basePrime[i]: 2 3 5 7 11 13 17 19 23 29 = true only in range[0,R]

    vector<bool> segSieveIsPrime(R-L+1, true); // size of segmented sieve is = 30 - 20 + 1 = 11
    // Step 3rd: segmented sieve: 20  21  22  23  24  25  26  27  28  29  30
    //   segSieveIsPrime[index]:  F   F   F   T   F   F   F   F   F   T   F
    //                    index:  0   1   2   3   4   5   6   7   8   9   10
    if(L == 1 || L == 0){
        segSieveIsPrime[L] = false;
    }

    // Which is starting index of segmented sieve is L
    // Index 0 ----> Renewable 20
    // Index 10 ---> Renewable 30
    for(auto prime : basePrime){

        int first_multiple = (L/prime)*prime;
        // Renewable Index first_multiple = (20/2)*2   = (10)*2 = 20 when prime = 2
        // Renewable Index first_multiple = (20/3)*3   = (6)*3  = 18 when prime = 3
        // Renewable Index first_multiple = (20/5)*5   = (4)*5  = 20 when prime = 5
        // Renewable Index first_multiple = (20/7)*7   = (2)*7  = 14 when prime = 7
        // Renewable Index first_multiple = (20/11)*11 = (1)*11 = 11 when prime = 11
        // Renewable Index first_multiple = (20/13)*13 = (1)*13 = 13 when prime = 13
        // Renewable Index first_multiple = (20/17)*17 = (1)*17 = 17 when prime = 17
        // Renewable Index first_multiple = (20/19)*19 = (1)*19 = 19 when prime = 19
        // Renewable Index first_multiple = (20/23)*23 = (0)*23 = 0  when prime = 23
        // Renewable Index first_multiple = (20/29)*29 = (0)*29 = 0  when prime = 29

        if(first_multiple < L){
            first_multiple += prime; 
        }
        // when (first_multiple > L ) then first_multiple = 20           when prime = 2
        // when (first_multiple < L ) then first_multiple = 18 + 3  = 21 when prime = 3
        // when (first_multiple == L) then first_multiple = 20           when prime = 5
        // when (first_multiple < L ) then first_multiple = 14 + 7  = 21 when prime = 7
        // when (first_multiple < L ) then first_multiple = 11 + 11 = 22 when prime = 11
        // when (first_multiple < L ) then first_multiple = 13 + 13 = 26 when prime = 13
        // when (first_multiple < L ) then first_multiple = 17 + 17 = 34 when prime = 17
        // when (first_multiple < L ) then first_multiple = 19 + 19 = 38 when prime = 19
        // when (first_multiple < L ) then first_multiple = 0 + 23  = 23 when prime = 23
        // when (first_multiple < L ) then first_multiple = 0 + 29  = 29 when prime = 29

        int j = max(first_multiple, prime*prime); 
        // j = max(20, 2*2) = max(20, 4)     = 20  when prime = 2   --> updated segSieveIsPrime vale are false: 20 22 24 26 28 30
        // j = max(21, 3*3) = max(21, 9)     = 21  when prime = 3   --> updated segSieveIsPrime vale are false: 21 24 27 30
        // j = max(20, 5*5) = max(20, 25)    = 25  when prime = 5   --> updated segSieveIsPrime vale are false: 25 30
        // j = max(21, 7*7) = max(21, 49)    = 49  when prime = 7   --> not updated because J<=R --> false
        // j = max(22, 11*11) = max(22, 121) = 121 when prime = 11  --> not updated because J<=R --> false
        // j = max(26, 13*13) = max(26, 169) = 169 when prime = 13  --> not updated because J<=R --> false
        // j = max(34, 17*17) = max(34, 289) = 289 when prime = 17  --> not updated because J<=R --> false
        // j = max(38, 19*19) = max(38, 361) = 361 when prime = 19  --> not updated because J<=R --> false
        // j = max(23, 23*23) = max(23, 529) = 529 when prime = 23  --> not updated because J<=R --> false
        // j = max(29, 29*29) = max(29, 841) = 841 when prime = 29  --> not updated because J<=R --> false
        while(j <= R){
            segSieveIsPrime[j - L] = false;
            j += prime;
        }
    }
    return segSieveIsPrime;
}

int main(){
    int L = 20;
    int R = 30;
    vector<bool> sieve = segSieve(L,R);
    for(int i=0;i<N;i++){
        if(sieve[i]){
            cout<<i + L<<" "; // Final Output: 23 and 29 are prime number in range [20,30]
        }
    }
    return 0;
}

/*
Examples: find Prime Numbers Between given Interval[Left,Right] (GFG)

Input : L = 1, R = 10
Output : 2, 3, 5, 7

Input : L = 10, R = 20
Output : 11, 13, 17, 19

Input : L = 110, R = 130
Output : 113, 127, 131
*/