#include <deque>
#include <iostream>
#include <queue>

using namespace std;

int main() {
  int att;
  cin >> att;

  while (att > 0) {
    int sz;
    cin >> sz;

    deque<int> dq;

    for (int i = sz; i > 0; i--) {
      dq.push_front(i);
      for (int j = 0; j < i; j++) {
        int x;
        x = dq.back();
        dq.push_front(x);
        dq.pop_back();
      }
    }

    for (int i = 0; i < dq.size(); i++) {
      cout << dq[i] << ' ';
    }
    cout << '\n';
    att--;
  }
}