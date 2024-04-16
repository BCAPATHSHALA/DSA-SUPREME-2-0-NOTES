// 10. Count set bits

#include <iostream>
using namespace std;

// Method I
bool slowCountSetBits(int n) {
	int count = 0;

	while(n != 0 ) {
		int lastbit = n & 1;
		if(lastbit) {
			count++;
		}
		n = n >> 1;
	}
    return count;
}

// Method II
int fastCountSetBits(int n) {
	int count = 0;
	while(n != 0) {
		count++;
		n = (n & (n-1));
	}
	return count;
}

int main() {
	int n = 10;
	cout<< slowCountSetBits(n) << endl;
	return 0;
}