#include <iostream>

using namespace std;

struct Node {
  int data;
  Node *next;
  Node(int x, Node *n) : data(x), next(n) {};
};

void push_back(int x, Node *&head, Node *&tail) {
  Node *new_n = new Node(x, nullptr);
  if (!head) {
    head = tail = new_n;
    return;
  } else {
    tail->next = new_n;
    tail = new_n;
  }
}

Node *delete_at(Node *head, int pos) {
  Node *temp = head;

  Node *prev = nullptr;
  for (int i = 0; i < pos; i++) {
    prev = temp;
    temp = temp->next;
  }

  prev->next = temp->next;
  delete temp;
  return head;
}

int main() {
  int n;

  cin >> n;

  Node *head = nullptr;
  Node *tail = nullptr;

  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;
    if (i % 2 == 0) {
      push_back(temp, head, tail);
    } else {
      continue;
    }
  }

  for (Node *curr = head; curr != nullptr; curr = curr->next) {
    cout << curr->data << " ";
  }

  return 0;
}