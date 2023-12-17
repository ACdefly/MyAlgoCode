#include <bits/stdc++.h>

using i64 = long long;

void solve() {
  int n, m, x;
  std::cin >> n >> m >> x;
  int a[n], b[m];
  for (int i = 0; i < n; i++)
    std::cin >> a[i];
  for (int i = 0; i < m; i++)
    std::cin >> b[i];
  for (int i = 0, j = m - 1; i < n;) {
    if (a[i] + b[j] > x)
      j--;
    else if (a[i] + b[j] < x)
      i++;
    else {
      std::cout << i << ' ' << j << std::endl;
      break;
    }
  }
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  solve();

  return 0;
}
