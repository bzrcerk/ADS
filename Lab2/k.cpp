#include <iostream>

using namespace std;

struct Node {
  char data;
  Node *next;

  Node(char x, Node *n = nullptr) : data(x), next(n) {};
};

void push_back(char val, Node *&head, Node *&tail) {
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

  while (n--) {
    Node *head = nullptr;
    Node *tail = nullptr;
    int len;
    cin >> len;

    int freq[26] = {0};

    for (int i = 0; i < len; i++) {
      char tmp;
      cin >> tmp;
      push_back(tmp, head, tail);

      freq[tmp - 'a']++;

      Node *cand = head;

      while (cand && freq[cand->data - 'a'] > 1) {
        cand = cand->next;
      }

      if (cand) {
        cout << cand->data << ' ';
      } else {
        cout << -1 << ' ';
      }
    }

    cout << endl;
    while (head) {
      Node *next = head->next;
      delete head;
      head = next;
    }
    tail = nullptr;
  }

  return 0;
}