// 5. Clear Ith bit from right side

#include <iostream>
using namespace std;

void clearIthBit(int &n, int i) {
	int mask = ~(1<<i);
	n = n & mask;
	cout << "Updated number: " << n << endl;
}

int main() {
	int n = 10;
    int i = 1;
	clearIthBit(n, i);
	return 0;
}