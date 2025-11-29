#include <iostream>
#include <set>
#include <string>
#include <vector>

#define ll long long

using namespace std;

const ll MOD1 = 1000000007LL;
const ll MOD2 = 1000000009LL;
const ll BASE1 = 31LL;
const ll BASE2 = 37LL;

int val(char c) { return c - 'a' + 1; }

pair<ll, ll> getHash(int l, int r, const vector<ll> &h1, const vector<ll> &h2,
                     const vector<ll> &p1, const vector<ll> &p2) {
  ll x1 = (h1[r] - h1[l] * p1[r - l]) % MOD1;
  ll x2 = (h2[r] - h2[l] * p2[r - l]) % MOD2;
  if (x1 < 0)
    x1 += MOD1;
  if (x2 < 0)
    x2 += MOD2;
  return {x1, x2};
}

int main() {
  string s;
  cin >> s;

  int n = s.size();

  vector<ll> h1(n + 1, 0), h2(n + 1, 0);
  vector<ll> p1(n + 1, 1), p2(n + 1, 1);

  for (int i = 1; i <= n; i++) {
    p1[i] = (p1[i - 1] * BASE1) % MOD1;
    p2[i] = (p2[i - 1] * BASE2) % MOD2;
  }

  for (int i = 0; i < n; i++) {
    h1[i + 1] = (h1[i] * BASE1 + val(s[i])) % MOD1;
    h2[i + 1] = (h2[i] * BASE2 + val(s[i])) % MOD2;
  }

  set<pair<ll, ll>> hashes;

  for (int len = 1; len <= n; len++) {
    for (int l = 0; l + len <= n; l++) {
      auto cur = getHash(l, len + l, h1, h2, p1, p2);
      hashes.insert(cur);
    }
  }

  cout << hashes.size();
  return 0;
}