// SET DATA STRUCTURE IN CPP
/*
📝 What is set data structure?
📝 How set data structure work?
📝 What is the time complexity of set data structure operation?
    insert: O(1)
    find: O(1)
    erase: o(1)
    
A set is a container that stores unique elements in sorted order. 
It is implemented using a self-balancing binary search tree. 
The set's elements can be added or deleted, but once they are added, they cannot be changed.

1. To add an element to a set, you use the insert() function. 
   The insert() function takes the element as a parameter and returns an iterator to the element. 
   If the element is already in the set, the insert() function does nothing and returns an iterator to the existing element.

2. To delete an element from a set, you use the erase() function. 
   The erase() function takes the element as a parameter and returns an iterator to the next element in the set. 
   If the element is not in the set, the erase() function does nothing and returns an iterator to the end of the set.

3. To check if an element is in a set, you use the find() function. 
   The find() function takes the element as a parameter and returns an iterator to the element if it is in the set. 
   If the element is not in the set, the find() function returns an iterator to the end of the set.

4. To iterate over the elements of a set, you use a for loop. 
   The for loop starts at the beginning of the set and ends at the end of the set. 
   The for loop iterates over the elements of the set in sorted order.


Here is an example of how to use a set in C++:
*/
#include<iostream>
#include<set>
using namespace std;

int main() {
  // Create a set of integers.
  set<int> mySet;

  // Add some elements to the set.
  mySet.insert(1);
  mySet.insert(2);
  mySet.insert(3);

  // Check if an element is in the set.
  if (mySet.find(2) != mySet.end()) {
    cout << "The element 2 is in the set." << std::endl;
  } else {
    cout << "The element 2 is not in the set." << std::endl;
  }

  // Delete an element from the set.
  mySet.erase(2);

  // Iterate over the elements of the set.
  for (set<int>::iterator it = mySet.begin(); it != mySet.end(); ++it) {
    cout << *it << endl;
  }

  return 0;
}

/*
Expected output:
The element 2 is in the set.
1
3
*/