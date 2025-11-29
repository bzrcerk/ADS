#include <climits>
#include <cstdint>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

#define ll long long

using namespace std;

const ll MOD1 = 1000000007;
const ll MOD2 = 1000000009;
const ll PW1 = 31;
const ll PW2 = 37;

int val(char c) { return c - 'a' + 1; }

pair<vector<ll>, vector<ll>> prefix_hash(const string &s, ll mod, ll pw) {
  int n = s.size();

  vector<ll> h(n + 1, 0), p(n + 1, 1);
  for (int i = 0; i < n; i++) {
    h[i + 1] = (h[i] * pw + (val(s[i])) % mod);
    p[i + 1] = (p[i] * pw) % mod;
  }

  return {h, p};
}

ll get_hash(const vector<ll> &h, const vector<ll> &p, int l, int r, ll mod) {
  ll res = (h[r] - h[l] * p[r - l]) % mod;
  if (res < 0)
    res += mod;
  return res;
}

string get_common_substring(const vector<string> &v, int len) {
  if (len == 0)
    return "";

  auto hp1 = prefix_hash(v[0], MOD1, PW1);
  auto hp2 = prefix_hash(v[0], MOD2, PW2);
  const vector<ll> &h1_0 = hp1.first;
  const vector<ll> &p1_0 = hp1.second;
  const vector<ll> &h2_0 = hp2.first;
  const vector<ll> &p2_0 = hp2.second;

  unordered_set<uint64_t> common;

  int n0 = (int)v[0].size();
  for (int i = 0; i + len <= n0; i++) {
    ll x1 = get_hash(h1_0, p1_0, i, i + len, MOD1);
    ll x2 = get_hash(h2_0, p2_0, i, i + len, MOD2);
    uint64_t key = (uint64_t(x1) << 32) ^ (uint64_t)x2;
    common.insert(key);
  }

  int k = (int)v.size();
  for (int idx = 1; idx < k; idx++) {
    auto hp1i = prefix_hash(v[idx], MOD1, PW1);
    auto hp2i = prefix_hash(v[idx], MOD2, PW2);
    const vector<ll> &h1 = hp1i.first;
    const vector<ll> &p1 = hp1i.second;
    const vector<ll> &h2 = hp2i.first;
    const vector<ll> &p2 = hp2i.second;

    unordered_set<uint64_t> cur;
    int n = (int)v[idx].size();
    for (int i = 0; i + len <= n; i++) {
      ll x1 = get_hash(h1, p1, i, i + len, MOD1);
      ll x2 = get_hash(h2, p2, i, i + len, MOD2);
      uint64_t key = (uint64_t(x1) << 32) ^ (uint64_t)x2;
      cur.insert(key);
    }

    unordered_set<uint64_t> next;
    for (uint64_t x : common) {
      if (cur.count(x))
        next.insert(x);
    }

    common.swap(next);
    if (common.empty())
      return "";
  }

  auto hpf1 = prefix_hash(v[0], MOD1, PW1);
  auto hpf2 = prefix_hash(v[0], MOD2, PW2);
  const vector<ll> &h1f = hpf1.first;
  const vector<ll> &p1f = hpf1.second;
  const vector<ll> &h2f = hpf2.first;
  const vector<ll> &p2f = hpf2.second;

  for (int i = 0; i + len <= (int)v[0].size(); i++) {
    ll x1 = get_hash(h1f, p1f, i, i + len, MOD1);
    ll x2 = get_hash(h2f, p2f, i, i + len, MOD2);
    uint64_t key = (uint64_t(x1) << 32) ^ (uint64_t)x2;
    if (common.count(key))
      return v[0].substr(i, len);
  }

  return "";
}

int main() {
  int k;
  cin >> k;

  vector<string> v(k);
  int r = INT_MAX;

  for (int i = 0; i < k; i++) {
    cin >> v[i];
    r = min<int>(r, v[i].size());
  }

  int l = 0;
  string ans;

  while (l <= r) {
    int mid = (l + r) / 2;
    string temp = get_common_substring(v, mid);
    if (!temp.empty()) {
      ans = temp;
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }

  cout << ans;

  return 0;
}