#include <climits>
#include <iostream>

using namespace std;

struct Node {
  int data;
  Node *next;

  Node(int x, Node *n = nullptr) : data(x), next(n) {};
};

void push_back(int val, Node *&head, Node *&tail) {
  Node *n = new Node(val);

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
    int temp;
    cin >> temp;
    push_back(temp, head, tail);
  }

  int sum = 0;
  int best_sum = INT_MIN;

  for (Node *curr = head; curr != nullptr; curr = curr->next) {
    sum += curr->data;

    if (sum > best_sum) {
      best_sum = sum;
    }

    if (sum < 0) {
      sum = 0;
    }
  }

  if (best_sum < 0) {
    cout << -1;
  } else {
    cout << best_sum;
  }

  return 0;
}