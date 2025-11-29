#include <climits>
#include <iostream>

using namespace std;

struct Node {
  int data;
  Node *next;

  Node(int x, Node *n = nullptr) : data(x), next(n) {};
};

void push_back(int v, Node *&head, Node *&tail) {

  Node *n = new Node(v);

  if (!head) {
    head = tail = n;
    return;
  }

  tail->next = n;
  tail = n;
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

  int sum = head->data;
  int best_sum = head->data;

  for (Node *curr = head->next; curr != nullptr; curr = curr->next) {

    if (sum < 0) {
      sum = curr->data;
    } else {
      sum += curr->data;
    }
    if (best_sum < sum) {
      best_sum = sum;
    }
  }
  cout << best_sum;

  return 0;
}