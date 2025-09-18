#include <climits>
#include <cmath>
#include <iostream>

using namespace std;

struct Node {
  int data;
  Node *next;
  Node(int x, Node *n) : data(x), next(n) {};
};

void push_back(Node *&head, Node *&tail, int x) {
  Node *n = new Node(x, nullptr);
  if (!head) {
    head = tail = n;
    return;
  } else {
    tail->next = n;
    tail = n;
  }
}

int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  int goal;

  Node *head = nullptr;
  Node *tail = nullptr;

  while (n != 0) {
    int x;
    cin >> x;
    push_back(head, tail, x);
    n--;
  }

  cin >> goal;

  int best_diff = INT_MAX;
  int index_best = -1;

  int index_now = 0;
  for (Node *curr = head; curr != nullptr; curr = curr->next, index_now++) {
    int diff = abs(curr->data - goal);
    if (diff < best_diff) {
      best_diff = diff;
      index_best = index_now;
    }
  }

  cout << index_best;

  while (head) {
    Node *temp = head->next;
    delete head;
    head = temp;
  }

  return 0;
}