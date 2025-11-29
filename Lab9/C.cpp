#include <iostream>
#include <vector>

#define vec vector<int>

using namespace std;

vec compLps(const string &patt) {
  int n = patt.size();
  vec lps(n, 0);

  int len = 0, i = 1;

  while (i < n) {
    if (patt[i] == patt[len]) {
      lps[i++] = ++len;
    } else if (len != 0) {
      len = lps[len - 1];
    } else {
      lps[i++] = 0;
    }
  }
}

vec c

int main() { return 0; }