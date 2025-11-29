#include <iostream>

using namespace std;

struct Node {
  string data;
  Node *next;
  Node *prev;

  Node(string val, Node *n = nullptr, Node *p = nullptr)
      : data(val), next(n), prev(p) {};
};

void add_front(string v, Node *&head, Node *&tail) {
  Node *n = new Node(v);
  n->next = head;
  n->prev = nullptr;

  if (head) {
    head->prev = n;
  } else {
    tail = n;
  }

  head = n;
  cout << "ok" << endl;
}

void add_back(string v, Node *&head, Node *&tail) {
  Node *n = new Node(v);
  n->next = nullptr;

  if (!head) {
    n->prev = nullptr;
    head = tail = n;
    cout << "ok" << endl;
    return;
  }

  n->prev = tail;
  tail->next = n;
  tail = n;
  cout << "ok" << endl;
}

void erase_front(Node *&head, Node *&tail) {
  if (!head) {
    cout << "error" << endl;
    return;
  }
  cout << head->data << endl;
  Node *old = head;
  head = head->next;
  if (head) {
    head->prev = nullptr;
  } else {
    tail = nullptr;
  }

  delete old;
}

void erase_back(Node *&head, Node *&tail) {
  if (!tail) {
    cout << "error" << endl;
    return;
  }
  cout << tail->data << endl;
  Node *old = tail;
  tail = tail->prev;
  if (tail) {
    tail->next = nullptr;
  } else {
    head = nullptr;
  }
  delete old;
}

void front(Node *head) {
  if (!head) {
    cout << "error" << endl;
    return;
  };
  cout << head->data << endl;
}

void back(Node *tail) {
  if (!tail) {
    cout << "error" << endl;
    return;
  }

  cout << tail->data << endl;
}

void clear(Node *&head, Node *&tail) {
  Node *curr = head;
  while (curr) {
    Node *tmp = curr->next;
    delete curr;
    curr = tmp;
  }
  head = tail = nullptr;
  cout << "ok" << endl;
}

int main() {

  Node *head = nullptr;
  Node *tail = nullptr;

  while (true) {
    string command;
    cin >> command;

    if (command == "add_front") {
      string val;
      cin >> val;
      add_front(val, head, tail);
    } else if (command == "add_back") {
      string val;
      cin >> val;
      add_back(val, head, tail);
    } else if (command == "erase_front") {
      erase_front(head, tail);
    } else if (command == "erase_back") {
      erase_back(head, tail);
    } else if (command == "front") {
      front(head);
    } else if (command == "back") {
      back(tail);
    } else if (command == "clear") {
      clear(head, tail);
    } else if (command == "exit") {
      cout << "goodbye" << endl;
      break;
    }
  }

  return 0;
}