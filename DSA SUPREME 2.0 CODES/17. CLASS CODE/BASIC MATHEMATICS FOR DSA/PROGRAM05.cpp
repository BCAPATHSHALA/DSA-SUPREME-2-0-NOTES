// PROGRAM 05: Modular Exponentiation for large numbers (GFG)
#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
		long long int PowMod(long long int x,long long int n,long long int M)
		{
		    long long int ans = 1;
		    
		    while(n > 0){
		        if(n & 1){
		            // n is odd
		            ans = (ans * x) % M;
		        }
		        
		        x = (x*x) % M;
		        n = n>>1;
		    }
		    return ans % M;
		}
};

int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	long long int x, n, m;
    	cin >> x >> n >> m;
    	Solution ob;
    	long long int ans = ob.PowMod(x, n, m);
    	cout << ans <<"\n";
    }
	return 0;
}