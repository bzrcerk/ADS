#include <iostream>
#include <map>
#include <string>
#include <vector>

#define ll long long

using namespace std;

const ll MOD1 = 1000000007LL;
const ll MOD2 = 1000000009LL;
const ll BASE1 = 31LL;
const ll BASE2 = 37LL;

int val(char c) { return c - 'a' + 1; }

pair<vector<ll>, vector<ll>> buildPrefixHash(const string &s, ll mod, ll base) {
  int n = s.size();
  vector<ll> h(n + 1, 0), p(n + 1, 1);

  for (int i = 0; i < n; i++) {
    h[i + 1] = (h[i] * base + val(s[i])) % mod;
    p[i + 1] = (p[i] * base) % mod;
  }

  return {h, p};
}

ll getSubstringHash(const vector<ll> &h, const vector<ll> &p, int l, int r,
                    ll mod) {
  ll res = (h[r] - h[l] * p[r - l]) % mod;
  if (res < 0)
    res += mod;
  return res;
}

int main() {
  string s;
  int q;

  cin >> s >> q;

  auto hp1 = buildPrefixHash(s, MOD1, BASE1);
  auto hp2 = buildPrefixHash(s, MOD2, BASE2);
  const vector<ll> &h1 = hp1.first;
  const vector<ll> &p1 = hp1.second;
  const vector<ll> &h2 = hp2.first;
  const vector<ll> &p2 = hp2.second;

  int n = s.size();

  map<pair<ll, ll>, int> cnt;

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j <= n; j++) {
      ll x1 = getSubstringHash(h1, p1, i, j, MOD1);
      ll x2 = getSubstringHash(h2, p2, i, j, MOD2);
      cnt[{x1, x2}]++;
    }
  }

  while (q--) {
    int l, r;
    cin >> l >> r;
    l--;

    ll x1 = getSubstringHash(h1, p1, l, r, MOD1);
    ll x2 = getSubstringHash(h2, p2, l, r, MOD2);

    cout << cnt[{x1, x2}] << '\n';
  }

  return 0;
}