#include <iostream>
#include <vector>

using namespace std;

int main() {
  // Create a 2D vector
  vector<vector<int>> arr(3, vector<int>(3, 0));

  // Initialize the 2D vector
  for (int i = 0; i < arr.size(); i++) {
    for (int j = 0; j < arr[i].size(); j++) {
      arr[i][j] = i * j;
    }
  }

  // Visualize the 2D vector
  for (int i = 0; i < arr.size(); i++) {
    for (int j = 0; j < arr[i].size(); j++) {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}