/*
 * @Author: wlun
 * @Date:   2023-08-21 23:25:42
 * @Last Modified by:   wlun
 * @Last Modified time: 2023-08-21 23:45:08
 */

#include <cstring>
#include <iostream>
#define inf 0x3f3f3f3f
using namespace std;

const int N = 210;
int d[N][N];
int n, m, k;

void floyd() {
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
}

int main() {
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j)
        d[i][j] = 0;
      else
        d[i][j] = inf;
    }
  }
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    d[a][b] = min(d[a][b], c);
  }
  while(k--)
  {
    int a, b;
    cin >> a >> b;
    if(d[a][b] > inf / 2) cout << "impossible" << endl;
    else cout << d[a][b] << endl;
  }
  return 0;
}
