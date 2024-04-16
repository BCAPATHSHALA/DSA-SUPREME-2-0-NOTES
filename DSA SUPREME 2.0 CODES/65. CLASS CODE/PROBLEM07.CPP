// 8. Clear n bits from last

#include <iostream>
using namespace std;

void clearLastIBits(int n, int i) {
	int mask = (-1 << i);
	n = n & mask;
	cout << "Updated number: " << n << endl;
}

int main() {
	int n = 15;
    int i = 3;
	clearLastIBits(n, i);
	return 0;
}