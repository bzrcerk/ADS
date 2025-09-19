#include <iostream>

using namespace std;

struct Node {
  string data;
  Node *next;
  Node(string x, Node *n) : data(x), next(n) {};
};

void push_back(Node *&head, Node *&tail, string x) {

  Node *n = new Node(x, nullptr);

  if (!head) {
    head = tail = n;
    return;
  } else {
    tail->next = n;
    tail = n;
  }
}

void pop_front(Node *&head) {
  Node *temp = head->next;
  delete head;
  head = temp;
}

int main() {
  int n, step;

  cin >> n >> step;

  Node *head = nullptr;
  Node *tail = nullptr;

  for (int i = 0; i < n; i++) {
    string str;
    cin >> str;
    push_back(head, tail, str);
  }

  for (int i = 0; i < step; i++) {
    Node *old = head;
    push_back(head, tail, head->data);
    pop_front(head);
  }

  for (Node *curr = head; curr != nullptr; curr = curr->next) {
    cout << curr->data << " ";
  }

  return 0;
}