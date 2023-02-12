#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Box5 {
public:
  int val;
  int *iptr;

  Box5(const class Box5 &other) {
    val = other.val;
    iptr = new int[10];
    for (int i = 0; i < 10; i++) {
      iptr[i] = other.iptr[i];
    }

    cout << "Box created from box: " << val << endl;
  }

  Box5(int val) : val{val} {
    cout << "Box created: " << val << endl;
    iptr = new int[10];
  }

  ~Box5() {
    delete[] iptr;
    cout << "Box deleted: " << val << endl;
  }
};

void test5() {
  // [1]

  vector<Box5> boxes;
  int numOfBoxes = 5;

  for (int i = 0; i < numOfBoxes; i++) { // Create
    Box5 b5(i);
    boxes.push_back(b5);
  }

  // [2]
  vector<Box5 *> boxptrs;
  for (int i = 0; i < 5; i++) { // Create
    Box5 *bptr = new Box5(i * 100);
    boxptrs.push_back(bptr);
  }

  // No size given
  while (!boxptrs.empty()) { // Delete
    Box5 *lastBoxPtr = boxptrs.back();
    boxptrs.pop_back();

    delete lastBoxPtr;
  }
}