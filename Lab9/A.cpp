#include <iostream>
#include <vector>

#define ll long long
#define vec vector<int>

using namespace std;

vec compLps(const string &patt) {
  int n = patt.size();
  vec lps(n, 0);

  int len = 0, i = 1;
  while (i < n) {
    if (patt[i] == patt[len]) {
      len++;
      lps[i] = len;
      i++;
    } else {
      if (len != 0) {
        len = lps[len - 1];
      } else {
        lps[i] = 0;
        i++;
      }
    }
  }

  return lps;
}

bool kmpSearch(const string &patt, const string &text, const vec &lps) {
  int n = text.size();
  int m = patt.size();

  int i = 0, j = 0;

  while (i < n) {
    if (text[i] == patt[j]) {
      i++;
      j++;

      if (j == m) {
        return true;
      }
    } else {
      if (j != 0) {
        j = lps[j - 1];
      } else {
        i++;
      }
    }
  }

  return false;
}

int minReps(const string &text, const string &patt) {
  string comb = text;

  vec lps = compLps(patt);

  int cnt = 1;
  while (comb.size() < patt.size()) {
    comb += text;
    cnt++;
  }

  if (kmpSearch(patt, comb, lps)) {
    return cnt;
  } else if (kmpSearch(patt, comb + text, lps)) {
    return cnt + 1;
  }

  return -1;
}

int main() {

  string text, patt;
  cin >> text >> patt;

  int res = minReps(text, patt);

  cout << res;

  return 0;
}