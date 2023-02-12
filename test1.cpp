#include <cassert>
#include <iostream>

using namespace std;

class NodeTest1 {
  friend ostream &operator<<(ostream &out, const NodeTest1 &n) {
    out << "N<" << n.value << ", " << (n.next != nullptr) << ">";
    return out;
  }

public:
  static int nodeCount;
  int value;
  NodeTest1 *next;

  explicit NodeTest1(int value = 0, NodeTest1 *next = nullptr)
      : value{value}, next{next} {
    ++nodeCount;
    cout << "Creating " << *this << ", total created: " << nodeCount << endl;
  }

  ~NodeTest1() {
    cout << "Deleting: " << *this;
    --nodeCount;
    cout << ", nodes remaining: " << nodeCount << endl;
  }
};

int NodeTest1::nodeCount = 0;

void test1() {
  // [1]
  NodeTest1 n1(1);
  NodeTest1 *n1ptr;
  n1ptr = &n1;
  assert(n1ptr != nullptr);
  // Delete 1
  //  delete n1ptr;
  n1ptr = nullptr; // So its not accidently used

  // [2]
  auto *n2ptr = new NodeTest1(3);
  // Delete 2
  delete n2ptr;
  n2ptr = nullptr;

  // [3]
  int n3Size = 10;
  auto *n3arr = new NodeTest1[10];
  for (int i = 0; i < (n3Size / 2); ++i) {
    NodeTest1 tmp(i * i);
    n3arr[i] = tmp;
  }
  // Delete 3
  delete[] n3arr;
  n3arr = nullptr;

  // [4]
  int n4start = 6;
  int n4end = 10;
  auto n4arr = new NodeTest1 *[n4end];

  for (int i = n4start; i < n4end; ++i) {
    auto *tmp = new NodeTest1(i * i);
    n4arr[i] = tmp;
  }
  // Delete 4
  // Requires for loop because initalized new in for loop
  for (int i = n4start; i < n4end; ++i) {
    delete n4arr[i];
    n4arr[i] = nullptr;
  }
  delete n4arr;
  n4arr = nullptr;
}
