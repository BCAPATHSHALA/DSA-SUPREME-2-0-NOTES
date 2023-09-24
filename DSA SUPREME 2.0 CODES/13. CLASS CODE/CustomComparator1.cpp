// ✅CUTOM COMPARATOR 01: SORT A VECTOR
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Printing Method
void print(vector<int> &v) {
  for (int i = 0; i < v.size(); ++i) {
    cout << v[i] << " ";
  }
  cout << endl;
}

// Custom Comparator ki return value always true ya false hoti hai
bool myComparator1(int &a, int &b) {
    return a > b; // decreasing order sorting
}

bool myComparator2(int &a, int &b) {
    return a < b; // increasing order sorting
}

int main() {
  vector<int> v = {44, 55, 22, 11, 33};
  
  cout<<"Vector"<<endl;
  print(v);

  cout<<"Increasing order sorting by default"<<endl;
  sort(v.begin(), v.end()); 
  print(v);

  cout<<"Decreasing order sorting by my comparator 1"<<endl;
  sort(v.begin(), v.end(), myComparator1);
  print(v);

  cout<<"Increasing order sorting by my comparator 2"<<endl;
  sort(v.begin(), v.end(), myComparator2);
  print(v);

  return 0;
}

/*
Vector
44 55 22 11 33 
Increasing order sorting by default
11 22 33 44 55 
Decreasing order sorting by my comparator 1 
55 44 33 22 11 
Increasing order sorting by my comparator 2 
11 22 33 44 55 
*/
