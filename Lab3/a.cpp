#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> goals;

  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    goals.push_back(tmp);
  }

  vector<vector<int>> snake;

  int r, c;
  cin >> r >> c;

  snake.resize(r);

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      int tmp;
      cin >> tmp;
      snake[i].push_back(tmp);
    }
  }

  for (int i = 0; i < goals.size(); i++) {
    bool found = false;
    int c_r = 0;

    while (!found && c_r < r) {
      bool asc = snake[c_r][0] <= snake[c_r][c - 1];
      int left = 0;
      int right = snake[c_r].size() - 1;

      while (left <= right && !found) {
        int mid = left + (right - left) / 2;
        int val = snake[c_r][mid];

        if (val == goals[i]) {
          cout << c_r << ' ' << mid << endl;
          found = true;
          break;
        }

        if (asc) {
          if (val < goals[i]) {
            left = mid + 1;
          } else {
            right = mid - 1;
          }

        } else {
          if (val < goals[i]) {
            right = mid - 1;
          } else {
            left = mid + 1;
          }
        }
      }
      c_r++;
    }

    if (!found) {
      cout << -1 << '\n';
    }
  }

  return 0;
}
