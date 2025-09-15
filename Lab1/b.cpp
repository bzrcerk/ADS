#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a(n), ans(n);

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  stack<int> st;

  for (int i = 0; i < n; i++) {
    while (!st.empty() && st.top() > a[i]) {
      st.pop();
    }
    if (st.empty()) {
      ans[i] = -1;
    } else {
      ans[i] = st.top();
    }
    st.push(a[i]);
  }

  for (int i = 0; i < n; i++) {
    cout << ans[i] << ' ';
  }

  return 0;
}