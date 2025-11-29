#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  int sum = 0;
  int mx = INT_MIN;

  vector<int> v;

  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;
    v.push_back(temp);
    sum += temp;
    mx = max(mx, temp);
  }

  int l = mx;
  int r = sum;

  while (l < r) {
    int mid = (l + r) / 2;
    int curr_sum = 0, block = 1;

    for (int i = 0; i < n; i++) {
      if (curr_sum + v[i] <= mid) {
        curr_sum += v[i];
      } else {
        block++;
        curr_sum = v[i];
      }
    }

    if (block <= m) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }

  cout << l;

  return 0;
}