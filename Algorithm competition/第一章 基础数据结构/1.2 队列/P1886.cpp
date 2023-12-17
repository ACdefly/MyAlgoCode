// Problem: P1886 滑动窗口 /【模板】单调队列
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1886
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>

using namespace std;

const int N = 1e6 + 10;

int hh = 0, tt = -1;

int a[N], q[N];

int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++) {
    if (hh <= tt && i - k + 1 > q[hh])
      hh++;
    while (hh <= tt && a[i] <= a[q[tt]])
      tt--;
    q[++tt] = i;
    if (i - k + 1 >= 0)
      cout << a[q[hh]] << (i == n - 1 ? '\n' : ' ');
  }
  hh = 0, tt = -1;
  for (int i = 0; i < n; i++) {
    if (hh <= tt && i - k + 1 > q[hh])
      hh++;
    while (hh <= tt && a[i] >= a[q[tt]])
      tt--;
    q[++tt] = i;
    if (i - k + 1 >= 0)
      cout << a[q[hh]] << (i == n - 1 ? '\n' : ' ');
  }
  return 0;
}
