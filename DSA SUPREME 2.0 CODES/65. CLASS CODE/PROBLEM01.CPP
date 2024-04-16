// 2. Check even or odd number

#include <iostream>
using namespace std;

void checkEvenOdd(int n) {
	if(n & 1) {
		cout << "Odd" << endl;
	}
	else {
		cout << "Even " << endl;
	}
}

int main() {
	int n = 15;
	checkEvenOdd(n);
	return 0;
}