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
    if (vec[i] % 2 == 0)
      cout << vec[i] << ' ';
    else {
      vec[i]++;
    }
  }

  return 0;
}