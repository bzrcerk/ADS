#include <iostream>
#include <string>

using namespace std;

struct Node {
  string data;
  Node *next;
  Node *prev;
  Node(string val, Node *n = nullptr, Node *p = nullptr)
      : data(val), next(n), prev(p) {};
};

void push_back(string val, Node *&head, Node *&tail) {
  Node *n = new Node(val, nullptr);
  if (!head) {
    head = tail = n;
    return;
  }
  n->prev = tail;
  tail->next = n;
  tail = n;
}

int main() {
  int n;

  Node *head = nullptr;
  Node *tail = nullptr;

  cin >> n;

  int len = 0;

  while (n--) {
    string data;
    cin >> data;
    if (!tail || tail->data != data) {
      push_back(data, head, tail);
      len++;
    }
  }

  cout << "All in all: " << len << endl;
  cout << "Students: " << endl;

  for (Node *curr = tail; curr != nullptr; curr = curr->prev) {
    cout << curr->data << endl;
  }

  return 0;
}