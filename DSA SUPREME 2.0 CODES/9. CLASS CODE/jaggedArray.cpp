// Jagged array
#include <iostream>
#include<vector>
using namespace std;

int main() {
  vector< vector<int> > arr;


  vector<int> vec1(10,0);
  vector<int> vec2(5,1);
  vector<int> vec3(7,0);
  vector<int> vec4(8,1);
  vector<int> vec5(20,0);

  arr.push_back(vec1);
  arr.push_back(vec2);
  arr.push_back(vec3);
  arr.push_back(vec4);
  arr.push_back(vec5);

  for(int i=0; i<arr.size(); i++) {
    for(int j=0; j<arr[i].size(); j++) {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
  
  
  return 0;
}