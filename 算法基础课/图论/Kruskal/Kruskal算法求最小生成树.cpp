/*
 * @Author: wlun
 * @Date:   2023-08-22 09:39:35
 * @Last Modified by:   wlun
 * @Last Modified time: 2023-08-22 09:52:48
 */
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 1e5 + 10;

typedef struct Edge {
  int u, v, w;
  bool operator<(const Edge &a) { return this->w < a.w; }
} Edge;

Edge edges[N << 1];
int p[N];
int n, m;

int find(int x) {
  if (x != p[x])
    p[x] = find(p[x]);
  return p[x];
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    p[i] = i;
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    edges[i] = {u, v, w};
  }
  sort(edges + 1, edges + (m + 1));
  int cnt = 0, sum = 0;
  for (int i = 1; i <= m; i++) {
    int u = edges[i].u, v = edges[i].v, w = edges[i].w;
    int x = find(u), y = find(v);
    if (x != y) {
      p[x] = y;
      cnt++;
      sum += w;
      if (cnt == n - 1) {
        cout << sum << endl;
        return 0;
      }
    }
  }
  cout << "impossible" << endl;
  return 0;
}
