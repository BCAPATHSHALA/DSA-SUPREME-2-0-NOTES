// 3. Get Ith bit from right side

#include <iostream>
using namespace std;

void getIthBit(int n,int i) {
	int mask = (1 << i);
	int num = n & mask;
	if(num == 0) {
		cout << "bit: 0" << endl;
	}
	else {
		cout << "bit: 1" << endl;
	}
}

int main() {
	int n = 10;
    int i = 3;
	getIthBit(n, i);
	return 0;
}