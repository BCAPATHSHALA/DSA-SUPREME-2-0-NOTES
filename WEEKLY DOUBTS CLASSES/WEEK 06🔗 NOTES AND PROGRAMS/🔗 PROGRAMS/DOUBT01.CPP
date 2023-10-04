// DOUBT 01: lower_bound/upper_bound example

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main () {
  int myints[] = {10,20,30,30,20,10,10,20}; // ARRAY
  vector<int> v(myints,myints+8);           // 10 20 30 30 20 10 10 20 COPY ARRAY

  sort (v.begin(), v.end());                // 10 10 10 20 20 20 30 30 SORTING ARRAY

  auto first = lower_bound(v.begin(), v.end(), 20);
  auto last = upper_bound(v.begin(), v.end(), 20); 

  cout << "Lower bound at position " << (first- v.begin()) <<endl;
  cout << "Upper bound at position " << (last - v.begin()) <<endl;

  cout << "Lower bound value " << (*first) <<endl;
  cout << "Upper bound value " << (*last) <<endl;

  return 0;
}

/*
Lower bound at position 3
Upper bound at position 6

Lower bound value 20
Upper bound value 30
*/

/*
Time complexity: log(N)+1 , where N is this distance between first and last position
*/