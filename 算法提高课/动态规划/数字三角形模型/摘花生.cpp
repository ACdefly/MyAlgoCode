/*
 * @Author: wlun
 * @Date:   2024-01-02 12:50:57
 * @Last Modified by:   wlun
 * @Last Modified time: 2024-01-02 13:15:00
 */
#include <iostream>

using namespace std;

const int N = 110;

int g[N][N];

void solve() {
  int r, c;
  cin >> r >> c;
  for (int i = 1; i <= r; i++) {
    for (int j = 1; j <= c; j++)
      cin >> g[i][j];
  }
  for (int i = 1; i <= r; i++) {
    for (int j = 1; j <= c; j++) {
      g[i][j] += max(g[i - 1][j], g[i][j - 1]);
    }
  }
  cout << g[r][c] << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
