#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

#define ll long long

using namespace std;

const ll MOD = 1000000007LL;
const ll BASE = 11LL;

string computeHash(const string &s) {
  long long h = 0;
  long long p = 1;

  for (char c : s) {
    ll value = (c - 47);
    h = (h + (value * p) % MOD) % MOD;
    p = (p * BASE) % MOD;
  }

  return to_string(h);
}

int main() {
  int n;
  cin >> n;

  vector<string> tokens;
  tokens.reserve(2 * n);

  unordered_set<string> available;
  available.reserve(2 * n * 2);

  for (int i = 0; i < 2 * n; i++) {
    string s;
    cin >> s;
    tokens.push_back(s);
    available.insert(s);
  }

  int matched = 0;

  for (int i = 0; i < tokens.size(); i++) {
    if (matched == n)
      break;

    string h = computeHash(tokens[i]);

    if (available.find(h) != available.end()) {
      cout << "Hash of string \"" << tokens[i] << "\" is " << h << "\n";
      matched++;
    }
  }

  return 0;
}