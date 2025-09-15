#include <iostream>
#include <queue>
using namespace std;

int main() {
  int n;
  cin >> n;

  string q;
  cin >> q;

  queue<int> q_s;
  queue<int> q_k;

  for (int i = 0; i < n; i++) {
    if (q[i] == 'S')
      q_s.push(i);
    else
      q_k.push(i);
  }

  while (!q_s.empty() && !q_k.empty()) {
    int i = q_s.front();
    q_s.pop();
    int j = q_k.front();
    q_k.pop();

    if (i < j) {
      q_s.push(i + n);
    } else {
      q_k.push(j + n);
    }
  }

  if (q_s.empty()) {
    cout << "KATSURAGI";
  } else {
    cout << "SAKAYANAGI";
  }

  return 0;
}