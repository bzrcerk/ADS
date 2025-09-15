#include <deque>
#include <iostream>

using namespace std;

int main() {
  deque<int> dq;
  char op;

  while (cin >> op && op != '!') {
    if (op == '+' || op == '-') {
      int x;
      cin >> x;

      if (op == '+') {
        dq.push_front(x);
      } else {
        dq.push_back(x);
      }

    } else if (op == '*') {
      if (dq.empty()) {
        cout << "error" << endl;
      } else {
        int sum = dq.front() + dq.back();
        cout << sum << endl;
        if (dq.size() == 1) {
          dq.pop_back();
        } else {
          dq.pop_front();
          dq.pop_back();
        }
      }
    }
  }

  return 0;
}