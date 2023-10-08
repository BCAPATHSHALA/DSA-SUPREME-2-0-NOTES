// ✅Optimising Sieve of Eratoshenes
vector<bool> Sieve(long long N){

    vector<bool> sieve(N+1,true);
    sieve[0]=sieve[1]=false;

    for(long long i=2; i*i<=N ; i++){ 
        if(sieve[i]){
            for(long long j=i*i; j<=N; j+=i){ 
                sieve[j]=false;
            }
        }
    }    
    return sieve;
}

// ✅Segmented Sieve
vector<bool> segSieve(long long L, long long R){
    vector<bool> sieve = Sieve(R); 
    
    vector<long long> basePrime; 
    for(long long i=0; i<sieve.size(); i++){
        if(sieve[i]){
            basePrime.push_back(i);
        }
    }
    
    vector<bool> segSieveIsPrime(R-L+1, true);
    if(L == 1 || L == 0){
        segSieveIsPrime[L] = false;
    }
    
    for(auto prime : basePrime){

        long long first_multiple = (L/prime)*prime;

        if(first_multiple < L){
            first_multiple += prime; 
        }

        long long j = max(first_multiple, prime*prime); 
        
        while(j <= R){
            segSieveIsPrime[j - L] = false;
            j += prime;
        }
    }
    return segSieveIsPrime;
}


// ✅Product of primes (GFG)
long long primeProduct(long long L, long long R){
        
    vector<bool> sieve = segSieve(L,R);
        
    long long product = 1;
    int mod = 1e9+7; // m = (1000000007) or m =10^9 + 7
    for(long long i=0; i<sieve.size(); i++){
            
        if(sieve[i]){
            // corner case
            if(L == 1 && i==0){
                i = 1;
            }
            product *=(i+L);
            product = product % mod;
        }
    }        
    return product;
}

/*
Problem statement:
Given two numbers L and R (inclusive) find the product of primes within this range. 
Print the product modulo 10^9+7. If there are no primes in that range you must print 1.

Example 1:
Input: L = 1, R = 10
Output: 210
Explaination: The prime numbers are 
2, 3, 5 and 7

Example 2:
Input: L = 1, R = 20
Output: 9699690
Explaination: The primes are 2, 3, 
5, 7, 11, 13, 17 and 19
*/