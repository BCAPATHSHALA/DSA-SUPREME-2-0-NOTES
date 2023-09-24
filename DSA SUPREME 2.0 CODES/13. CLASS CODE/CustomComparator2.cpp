// ✅CUTOM COMPARATOR 02: SORT VECTOR OF VECTOR
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// Printing Method
void print(vector<vector<int>> &v) {
  for (int i = 0; i < v.size(); ++i) {
    vector<int> &temp = v[i];
    int a = temp[0];
    int b = temp[1];
    cout << a << " " << b << endl;
  }
  cout << endl;
}

// Custom Comparator ki return value always true ya false hoti hai
bool myComparator1(vector<int> &a, vector<int> &b) {
    return a[0] > b[0]; // decreasing order sorting by 1st index
}

bool myComparator2(vector<int> &a, vector<int> &b) {
    return a[1] > b[1]; // decreasing order sorting by 2nd index
}

int main() {
    // vector of vector sorting
    vector<vector<int>> v;

    int n;
    cout << "Enter size:\n";
    cin >> n;

    // Taking input from user in 2D vector
    for (int i = 0; i < n; ++i) {
    
        int a, b;
        cout << "Enter a, b" << endl;
        cin >> a >> b;

        // Creation of 1D vector temp
        vector<int> temp;

        // Inserting element a at 0th and b at 1st index in 1D vector
        temp.push_back(a);
        temp.push_back(b);

        // Inserting 1D vector temp in 2D vector v
        v.push_back(temp);
    }

    cout << "Here are the Values" << endl;
    print(v);

    cout << "Sorted by 1st index" << endl;
    sort(v.begin(), v.end(), myComparator1);
    print(v);

    cout << "Sorted by 2st index" << endl;
    sort(v.begin(), v.end(), myComparator2);
    print(v);

    return 0;
}

/*
Enter size:
5
Enter a, b
1
44
Enter a, b
0
55
Enter a, b
0
22
Enter a, b
0
11
Enter a, b
2
33
Here are the Values
1 44
0 55
0 22
0 11
2 33

Sorted by 1st index
2 33
1 44
0 55
0 22
0 11

Sorted by 2st index
0 55
1 44
2 33
0 22
0 11
*