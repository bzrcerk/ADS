#include <iostream>

using namespace std;

struct Node {
  int data;
  Node *next;

  Node(int x, Node *n = nullptr) : data(x), next(n) {};
};

void insert(Node *&head, int x, int p) {
  Node *n = new Node(x);

  if (!head) {
    head = n;
    return;
  }

  if (p == 0) {
    n->next = head;
    head = n;
    return;
  }

  Node *tmp = head;

  for (int i = 1; i < p; i++) {
    tmp = tmp->next;
  }

  n->next = tmp->next;
  tmp->next = n;

  return;
}

void remove(Node *&head, int p) {

  if (p == 0) {
    Node *del = head;
    head = head->next;
    delete del;
    return;
  }

  Node *prev = head;
  for (int i = 1; i < p; i++) {
    prev = prev->next;
  }

  Node *del = prev->next;
  prev->next = del->next;
  delete del;
  return;
}

void replace(Node *&head, int p1, int p2) {
  Node *tmp1 = head;
  int tmp1_data;

  for (int i = 0; i < p1 - 1; i++) {
    tmp1 = tmp1->next;
  }
  Node *del = nullptr;
  int goal_data = 0;
  if (p1 == 0) {
    Node *del = head;
    goal_data = head->data;
    head = head->next;
  } else {
    Node *del = tmp1->next;
    goal_data = tmp1->next->data;
  }

  tmp1->next = tmp1->next->next;
  delete del;

  Node *n = new Node(goal_data);
  if (p2 == 0) {
    n->next = head;
    head = n;
    return;
  }

  Node *tmp2 = head;

  for (int i = 0; i < p2 - 1; i++) {
    tmp2 = tmp2->next;
  }
  n->next = tmp2->next;
  tmp2->next = n;
  return;

  return;
}

void reverse(Node *&head) {
  Node *prev = nullptr;
  Node *curr = head;

  while (curr) {
    Node *next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }

  head = prev;
}

void print(Node *head) {
  for (Node *curr = head; curr != nullptr; curr = curr->next) {
    cout << curr->data << ' ';
  }
  cout << endl;
}

void cyclic_left(Node *&head, int x) {
  if (x == 0)
    return;

  Node *tail = head;
  while (tail->next) {
    tail = tail->next;
  }

  Node *new_tail = head;
  for (int i = 0; i < x - 1; i++) {
    new_tail = new_tail->next;
  }
  Node *new_head = new_tail->next;

  tail->next = head;
  new_tail->next = nullptr;
  head = new_head;
}

void cyclic_right(Node *&head, int x) {
  if (x == 0)
    return;
  int n = 1;
  Node *tail = head;
  while (tail->next) {
    tail = tail->next;
    ++n;
  }

  int left = n - x;

  Node *new_tail = head;
  for (int i = 1; i < left; ++i)
    new_tail = new_tail->next;
  Node *new_head = new_tail->next;

  tail->next = head;
  new_tail->next = nullptr;
  head = new_head;
}

int main() {
  Node *head = nullptr;
  while (true) {
    int command;
    cin >> command;
    if (command == 0) {
      break;
    } else if (command == 1) {
      int x, p;
      cin >> x >> p;
      insert(head, x, p);
    } else if (command == 2) {
      int p;
      cin >> p;
      remove(head, p);
    } else if (command == 3) {
      print(head);
    } else if (command == 4) {
      int p1, p2;
      cin >> p1 >> p2;
      replace(head, p1, p2);
    } else if (command == 5) {
      reverse(head);
    } else if (command == 6) {
      int x;
      cin >> x;
      cyclic_left(head, x);
    } else if (command == 7) {
      int x;
      cin >> x;
      cyclic_right(head, x);
    }
  }

  return 0;
}