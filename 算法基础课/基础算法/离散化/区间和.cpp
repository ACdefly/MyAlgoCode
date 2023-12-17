/*
 * @Author: wlun
 * @Date:   2023-08-08 22:13:50
 * @Last Modified by:   wlun
 * @Last Modified time: 2023-08-08 23:07:11
 */

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <vector>

using i64 = long long;

const int N = 1e5 + 10;
int a[N], s[N]; // a存的是值, s存的是前缀和

std::vector<int> alls; // alls存的是所有下标 x, l, r
std::vector<std::pair<int, int>> add, query; // add存n次操作, query村m次询问

int find(int x) {
  int l = 0, r = alls.size() - 1;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (alls[mid] >= x)
      r = mid;
    else
      l = mid + 1;
  }
  return l + 1;
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  std::cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int x, c;
    std::cin >> x >> c;
    add.push_back({x, c});
    alls.push_back(x);
  }
  for (int i = 0; i < m; i++) {
    int l, r;
    std::cin >> l >> r;
    query.push_back({l, r});
    alls.push_back(l);
    alls.push_back(r);
  }
  // 去重
  std::sort(alls.begin(), alls.end());
  alls.erase(std::unique(alls.begin(), alls.end()), alls.end());

  // 处理插入
  for (auto &item : add) {
    int x = find(item.first);
    a[x] += item.second;
  }
  for (std::size_t i = 1; i <= alls.size(); i++)
    s[i] = s[i - 1] + a[i];
  for (int i = 0; i < m; i++) {
    int l = find(query[i].first), r = find(query[i].second);
    std::cout << s[r] - s[l - 1] << "\n";
  }
  return 0;
}
