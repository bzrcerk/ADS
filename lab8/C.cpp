#include <iostream>
#include <string>
#include <vector>

#define ll long long

using namespace std;

const ll MOD = 1000000007LL;
const ll BASE = 31LL;

int val(char c) { return c - 'a' + 1; }

void buildPrefixHash(const string &text, vector<ll> &pref, vector<ll> &power) {
  int n = text.size();

  for (int i = 0; i < n; i++) {
    pref[i + 1] = (pref[i] * BASE + (val(text[i])) % MOD);
    power[i + 1] = (power[i] * BASE) % MOD;
  }
}

ll getSubstringHash(const vector<ll> &pref, const vector<ll> &power, int l,
                    int r) {
  ll res = (pref[r] - pref[l] * power[r - l]) % MOD;
  if (res < 0)
    res += MOD;
  return res;
}

int main() {
  string s;
  cin >> s;

  int n = s.size();
  string covered(n, '0');

  vector<ll> prefix(n, 0), power(n, 1);
  buildPrefixHash(s, prefix, power);

  int q;
  cin >> q;

  while (q--) {
    string t;
    cin >> t;

    int m = t.size();
    ll hashT = 0;

    for (char c : t)
      hashT = (hashT * BASE + val(c)) % MOD;

    for (int i = 0; i + m <= n; i++) {
      ll cur = getSubstringHash(prefix, power, i, i + m);
      if (cur == hashT) {
        for (int k = i; k < i + m; k++)
          covered[k] = '1';
      }
    }
  }

  for (char c : covered) {
    if (c == '0') {
      cout << "NO";
      return 0;
    }
  }

  cout << "YES";
  return 0;
}