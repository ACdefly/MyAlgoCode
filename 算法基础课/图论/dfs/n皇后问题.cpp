/*
 * @Author: wlun
 * @Date:   2023-08-21 15:13:18
 * @Last Modified by:   wlun
 * @Last Modified time: 2023-08-21 15:13:46
 */

#include <cstring>
#include <iostream>

using namespace std;

const int N = 10;
char g[N][N];
bool col[N], dg[N << 1], udg[N << 1];
int n;

void dfs(int u) {
  if (u > n) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        cout << g[i][j];
      }
      cout << endl;
    }
    cout << endl;
    return;
  }
  int x = u;
  for (int y = 1; y <= n; y++) {
    if (!col[y] && !dg[y - x + n] && !udg[y + x]) {
      g[x][y] = 'Q';
      col[y] = dg[y - x + n] = udg[y + x] = true;
      dfs(x + 1);
      col[y] = dg[y - x + n] = udg[y + x] = false;
      g[x][y] = '.';
    }
  }
}

int main() {
  memset(g, '.', sizeof(g));
  cin >> n;
  dfs(1);
  return 0;
}
