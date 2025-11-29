#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;

  cin >> n;

  vector<int> vec;

  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;

    vec.push_back(temp);
  }

  for (int i = 0; i < n; i++) {
    cout << vec[i] << ' ';
  }

  return 0;
}