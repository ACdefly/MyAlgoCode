/*
 * @Author: wlun
 * @Date:   2023-08-08 23:16:49
 * @Last Modified by:   wlun
 * @Last Modified time: 2023-08-08 23:30:55
 */

#include <algorithm>
#include <iostream>
#include <vector>
#define l first
#define r second

using i64 = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<std::pair<int, int>> alls(n);

  for (int i = 0; i < n; i++) {
    std::cin >> alls[i].l >> alls[i].r;
  }
  std::sort(alls.begin(), alls.end());
  int sum = 1;
  int r = alls[0].r;
  for (int i = 1; i < n; i++) {
    if (alls[i].l <= r)
      r = std::max(alls[i].r, r);
    else {
      sum++;
      r = alls[i].r;
    }
  }
  std::cout << sum << std::endl;
  return 0;
}
