#include <iostream>
#include <vector>

#define ll long long
#define vec vector<int>

using namespace std;

vec compLps(const string &patt) {
  int m = patt.size();
  vec lps(m, 0);

  int len = 0, i = 1;

  while (i < m) {
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

int kmpSearch(const string &text, const string &patt) {
  int n = text.size();
  int m = patt.size();
  int cnt = 0;

  vec lps = compLps(patt);

  int i = 0, j = 0;

  while (i < n) {
    if (text[i] == patt[j]) {
      i++;
      j++;

      if (j == m) {
        cnt++;
        j = lps[j - 1];
      }
    } else {
      if (j != 0) {
        j = lps[j - 1];
      } else {
        i++;
      }
    }
  }

  return cnt;
}

int main() {
  string patt;
  int n;
  string text;

  cin >> patt >> n;

  cin >> text;

  int res = kmpSearch(text, patt);

  if (res >= n) {
    cout << "YES";
  } else {
    cout << "NO";
  }

  return 0;
}