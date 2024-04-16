// 9. Check power of two

#include <iostream>
using namespace std;

// Method I
bool checkPowerOf2(int n) {
	// Count set bit
	int count = 0;

	while(n != 0 ) {
		int lastbit = n & 1;
		if(lastbit) {
			count++;
		}
		n = n >> 1;
	}

	if(count == 1 ){
        // Power of two
		return true;
	}
	else {
        // Not power of two
		return false;
	}	
}

// Method II
bool fastCheckPowerOf2(int n) {
	if((n & (n-1)) == 0)
		return true;
	else 
		return false;
}

int main() {
	int n = 4;
	cout<< fastCheckPowerOf2(n) << endl;
	return 0;
}