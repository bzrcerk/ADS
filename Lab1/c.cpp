#include <iostream>
#include <stack>
using namespace std;

int main() {

  string string1, string2;
  cin >> string1 >> string2;
  stack<char> st1, st2;

  for (int i = 0; i < string1.size(); i++) {
    if (string1[i] != '#') {
      st1.push(string1[i]);
    } else {
      st1.pop();
    }
  }
  for (int i = 0; i < string2.size(); i++) {
    if (string2[i] != '#') {
      st2.push(string2[i]);
    } else {
      st2.pop();
    }
  }

  if (st1 == st2) {
    cout << "Yes";
  } else {
    cout << "No";
  }
}