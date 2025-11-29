#include <iostream>
#include <string>
#include <vector>

#define ll long long

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector<ll> power(n, 1);

  for (int i = 1; i < n; i++) {
    power[i] = power[i - 1] * 2;
  }

  string s;
  s.reserve(n);

  for (int i = 0; i < n; i++) {
    ll code;
    if (i == 0) {
      code = a[i] + 97;
    } else {
      code = (a[i] - a[i - 1]) / power[i] + 97;
    }
    s.push_back(char(code));
  }

  cout << s;
  return 0;
}