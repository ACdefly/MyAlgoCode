/*
 * @Author: wlun
 * @Date:   2024-01-02 12:56:23
 * @Last Modified by:   wlun
 * @Last Modified time: 2024-01-02 13:15:08
 */

#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;

const int N = 110;

int w[N][N];
int f[N][N];

void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      cin >> w[i][j];
  memset(f, 0x3f, sizeof f);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == 1 && j == 1)
        f[i][j] = w[i][j];
      else {
        f[i][j] = min(f[i - 1][j] + w[i][j], f[i][j - 1] + w[i][j]);
      }
    }
  }
  cout << f[n][n] << endl;
}

int main() {
  int t;
  // cin >> t;
  t = 1;
  while (t--)
    solve();
  return 0;
}
