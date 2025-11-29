#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define ll long long

using namespace std;

const ll MOD = 1000000007LL;
const ll BASE = 31LL;

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
  while (true) {
    int n;
    if (!(cin >> n)) {
      return 0;
    }
    if (n == 0) {
      break;
    }

    vector<string> patterns(n);
    for (int i = 0; i < n; i++) {
      cin >> patterns[i];
    }

    string text;
    cin >> text;

    int textLenP = text.size();

    vector<ll> prefix(textLenP + 1, 0), power(textLenP + 1, 1);
    buildPrefixHash(text, prefix, power);

    int textLen = text.size();
    vector<ll> counts(n, 0);
    ll maxCount = 0;

    for (int i = 0; i < n; i++) {
      const string &pat = patterns[i];
      int m = pat.size();

      ll hashPat = 0;
      for (char c : pat) {
        hashPat = (hashPat * BASE + val(c)) % MOD;
      }

      ll cnt = 0;
      for (int start = 0; start + m <= textLen; start++) {
        ll hSub = getSubstringHash(prefix, power, start, start + m);
        if (hSub == hashPat) {
          cnt++;
        }
      }

      counts[i] = cnt;
      if (cnt > maxCount) {
        maxCount = cnt;
      }
    }

    cout << maxCount << '\n';
    for (int i = 0; i < n; i++) {
      if (counts[i] == maxCount) {
        cout << patterns[i] << '\n';
      }
    }
  }

  return 0;
}