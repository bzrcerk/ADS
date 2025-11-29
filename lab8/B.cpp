#include <iostream>
#include <string>
#include <vector>

#define ll long long

using namespace std;

const ll MOD = 1e7 + 7;
const ll BASE = 31;

int val(char c) { return c - 'a' + 1; }

void buildPrefixHash(const string &text, vector<ll> &prefix,
                     vector<ll> &power) {
  int n = text.size();

  for (int i = 0; i < n; i++) {
    prefix[i + 1] = (prefix[i] * BASE + (val(text[i])) % MOD);
    power[i + 1] = (power[i] * BASE) % MOD;
  }
}

ll getSubstringHash(const vector<ll> &prefix, const vector<ll> &power, int l,
                    int r) {
  ll res = (prefix[r] - prefix[l] * power[r - l]) % MOD;
  if (res < 0)
    res += MOD;
  return res;
}

int main() {
  string s1, s2, t;
  cin >> s1 >> s2 >> t;

  int n1 = s1.size();
  int n2 = s2.size();
  int m = t.size();

  vector<ll> prefix1(n1, 0), prefix2(n2, 0);
  vector<ll> power(max(n1, n2), 1);

  buildPrefixHash(s1, prefix1, power);
  buildPrefixHash(s2, prefix2, power);

  ll hashT = 0;
  for (char c : t) {
    hashT = (hashT * BASE + val(c)) % MOD;
  }

  int matches = 0;

  for (int i = 0; i + m <= min(n1, n2); i++) {
    ll hashS1 = getSubstringHash(prefix1, power, i, i + m);
    ll hashS2 = getSubstringHash(prefix2, power, i, i + m);

    if (hashS1 == hashT && hashS2 == hashT) {
      matches++;
    }
  }

  cout << matches;

  return 0;
}