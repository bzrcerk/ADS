#include <iostream>

using namespace std;

struct Node {
  int data;
  Node *next;
  Node(int x, Node *n) : data(x), next(n) {};
};

struct Freq {
  int val;
  int cnt;
  Freq *next;

  Freq(int x, int y = 1, Freq *n = nullptr) : val(x), cnt(y), next(n) {};
};

void increment_freq(Freq *&fhead, int val) {
  for (Freq *curr = fhead; curr != nullptr; curr = curr->next) {
    if (curr->val == val) {
      curr->cnt++;
      return;
    }
  }
  fhead = new Freq(val, 1, fhead);
}

void push_back(int data, Node *&head, Node *&tail) {
  Node *n = new Node(data, nullptr);
  if (!head) {
    head = tail = n;
    return;
  }
  tail->next = n;
  tail = n;
}

void ins_desc(Node *&head, int val) {
  Node *new_n = new Node(val, nullptr);
  if (!head || head->data < val) {
    new_n->next = head;
    head = new_n;
    return;
  }
  Node *curr = head;
  while (curr->next && curr->next->data >= val) {
    curr = curr->next;
  }

  new_n->next = curr->next;
  curr->next = new_n;
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

  Freq *fhead = nullptr;
  for (Node *curr = head; curr != nullptr; curr = curr->next) {
    increment_freq(fhead, curr->data);
  }

  int best = 0;

  for (Freq *curr = fhead; curr != nullptr; curr = curr->next) {
    if (curr->cnt > best) {
      best = curr->cnt;
    }
  }

  Node *modes = nullptr;
  for (Freq *curr = fhead; curr != nullptr; curr = curr->next) {
    if (curr->cnt == best) {
      ins_desc(modes, curr->val);
    }
  }

  for (Node *curr = modes; curr; curr = curr->next) {
    cout << curr->data << ' ';
  }

  return 0;
}