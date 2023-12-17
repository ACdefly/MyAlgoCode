/*
 * @Author: wlun
 * @Date:   2023-08-21 15:11:24
 * @Last Modified by:   wlun
 * @Last Modified time: 2023-08-21 15:13:00
 */

/*
 * @Author: wlun
 * @Date:   2023-08-21 15:11:24
 * @Last Modified by:   wlun
 * @Last Modified time: 2023-08-21 15:11:24
 */
#include <bits/stdc++.h>

using namespace std;

const int N = 110;
bool st[N];
int a[N];
int n;

void dfs(int u) {
  if (u > n) {
    for (int i = 1; i <= n; i++)
      cout << a[i] << ' ';
    cout << endl;
    return;
  }
  for (int i = 1; i <= n; i++) {
    if (!st[i]) {
      a[u] = i;
      st[i] = true;
      dfs(u + 1);
      st[i] = false;
    }
  }
}

int main() {
  cin >> n;
  dfs(1);
  return 0;
}
