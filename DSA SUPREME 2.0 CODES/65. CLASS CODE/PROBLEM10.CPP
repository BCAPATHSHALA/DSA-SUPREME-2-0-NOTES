// 11. Clear bits in range

#include <iostream>
using namespace std;

void clearBitsInRange(int n, int i, int j) {
	int a = (-1 << (i+1));
	int b = ~(-1 << j);
	int mask = a | b;
	n = n & mask;
	cout << "Updated number: " << n << endl;
}

int main() {
	int n = 255;
    int i = 4;
    int j = 1;
	clearBitsInRange(n, i, j);
	return 0;
}