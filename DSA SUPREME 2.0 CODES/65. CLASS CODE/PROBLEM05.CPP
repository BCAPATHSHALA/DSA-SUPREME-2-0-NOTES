// 6. Update Ith bit from right side

#include <iostream>
using namespace std;

void clearIthBit(int &n, int i) {
	int mask = ~(1<<i);
	n = n & mask;
}

void udpateIthBit(int n, int i, int target) {
	// Step 1: clear ith bit
	clearIthBit(n, i);

	// Step 2: create mask
	int mask = (target << i);

	// Step 3: update n
	n = n | mask;
	cout << "Updated number: " << n << endl;
}

int main() {
	int n = 10;
    int i = 3;
    int target = 0;
	udpateIthBit(n, i, target);
	return 0;
}