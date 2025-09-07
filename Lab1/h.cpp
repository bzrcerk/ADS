#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  bool isPrime;
  isPrime = true;

  if (n < 2) {
    isPrime = false;
    cout << "NO" << endl;
    return 0;
  }

  for (int i = 2; i < n; i++) {
    if (n % i == 0) {
      isPrime = false;
    }
  }

  if (isPrime) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

  return 0;
}