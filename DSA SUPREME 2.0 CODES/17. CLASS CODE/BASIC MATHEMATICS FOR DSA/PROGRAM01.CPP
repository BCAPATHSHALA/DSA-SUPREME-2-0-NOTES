// PROGRAM 01: Count primes (Leetcode-204)

// ✅APPROACH 01: Naive --> Total T.C. = O(N^2) and S.C. = O(1)
class Solution {
public:

    bool naiveAppIsPossible(int n){
        if(n<=1) return false;

        for(int i=2; i<n; i++){ // T.C. of inner loop is O(N)
            if(n%i == 0){
                return false;
            }
        }
        return true;
    }

    int countPrimes(int n) {
        int count = 0;

        for(int i=0; i < n; i++){ // T.C. of outer loop is O(N)
            if(naiveAppIsPossible(i)){
                count++;
            }
        } 
        return count;    
    }
    // T.C. of countPrimes() is O(N) * O(N) = O(N^2)
};


// ✅APPROACH 02: SQRT --> T.C. = O(N√N) and S.C. = O(1)
class Solution {
public:
    
    bool sqrtAppIsPossible(int n){
        if(n<=1) return false;

        int sqrtN = sqrt(n); // T.C. of sqrt() is O(logN)

        for(int i=2; i<=sqrtN; i++){ // T.C. of inner loop is O(√N)
            if(n%i == 0){
                return false;
            }
        }
        return true;
        // T.C. of sqrtAppIsPossible() is O(logN) + O(√N) = O(√N)
    }

    int countPrimes(int n) {
        int count = 0;

        for(int i=0; i < n; i++){ // T.C. of outer loop is O(N)
            if(sqrtAppIsPossible(i)){
                count++;
            }
        } 
        return count;    
    }
    // T.C. of countPrimes is O(√N) * O(N) = O(N√N)
};


// ✅APPROACH 03: Sieve of Eratoshenes --> T.C. = O(N * (log(log N))) and S.C. = O(N)
class Solution {
public:
    int countPrimes(int n) {
        if(n == 0) return 0;

        vector<bool> prime(n+1,true); // Step 01: all are prime marked already (true)
        prime[0]= prime[1]= false;

        int count = 0;

        for(int i=2; i < n; i++){ // T.C. of outer loop is O(N)

            // Step 02
            if(prime[i]){
                count++;
                for(int j=2*i; j<n; j+=i){ // T.C of inner loop O(log(log N))
                    prime[j] = false;
                }
            }
        } 
        return count;    
    }
    // T.C. of countPrimes is O(N) *  O(log(log N)) = O(N * (log(log N)))
};

/*
Problem Statement:
Given an integer n, return the number of prime numbers that are strictly less than n. 

Example 1:
Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

Example 2:
Input: n = 0
Output: 0

Example 3:
Input: n = 1
Output: 0
*/