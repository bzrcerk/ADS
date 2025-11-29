#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int lower_bound(vector<int> arr, int l) {
  int left = 0;
  int right = arr.size();

  while (left < right) {
    int mid = (right + left) / 2;
    if (arr[mid] < l) {
      left = mid + 1;
    } else {
      right = mid;
    }
  }
  return left;
}

int upper_bound(vector<int> arr, int r) {
  int left = 0;
  int right = arr.size();

  while (left < right) {
    int mid = (right + left) / 2;
    if (arr[mid] <= r) {
      left = mid + 1;
    } else {
      right = mid;
    }
  }
  return left;
}

int main() {
  int n, q;
  cin >> n >> q;
  vector<int> arr;

  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;
    arr.push_back(temp);
  }

  sort(arr.begin(), arr.end());

  while (q--) {
    int l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    int low_1 = lower_bound(arr, l1);
    int up_1 = upper_bound(arr, r1);
    int low_2 = lower_bound(arr, l2);
    int up_2 = upper_bound(arr, r2);

    int res = (up_1 - low_1) + (up_2 - low_2);
    cout << res << endl;
  }

  return 0;
}