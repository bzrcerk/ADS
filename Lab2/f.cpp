#include <iostream>

using namespace std;

struct Node {
  int data;
  Node *next;

  Node(int x, Node *n = nullptr) : data(x), next(n) {};
};

void push_back(int v, Node *&head, Node *&tail) {
  Node *n = new Node(v, nullptr);
  if (!head) {
    head = tail = n;
    return;
  }
  tail->next = n;
  tail = n;
}

void ins_at_pos(int v, Node *&head, int pos) {
  Node *tmp = head;

  if (pos == 0) {
    head = new Node(v, head);
    return;
  }

  while (tmp->next && pos--) {
    tmp = tmp->next;
  }

  tmp->next = new Node(v, tmp->next);
}

int main() {
  int n;
  cin >> n;

  Node *head = nullptr;
  Node *tail = nullptr;

  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    push_back(tmp, head, tail);
  }

  int pos, val;
  cin >> val;
  cin >> pos;
  if (pos != 0) {
    pos--;
  }
  ins_at_pos(val, head, pos);

  for (Node *curr = head; curr != nullptr; curr = curr->next) {
    cout << curr->data << ' ';
  }

  return 0;
}