/*
 * @Author: wlun
 * @Date:   2023-08-22 12:22:03
 * @Last Modified by:   wlun
 * @Last Modified time: 2023-08-22 12:55:59
 */
#include <cstring>
#include <iostream>
#include <queue>
#define inf 0x3f3f3f3f

using namespace std;

const int N = 1e5 + 10;
int e[N], ne[N], h[N], w[N], idx = 0;
int dist[N];
bool st[N];
int n, m;

void add(int a, int b, int c) {
  w[idx] = c, e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

queue<int> q;

void spfa() {
  memset(dist, 0x3f, sizeof dist);
  dist[1] = 0;
  st[1] = true;
  q.push(1);
  while (!q.empty()) {
    auto u = q.front();
    q.pop();
    st[u] = false;
    for (int i = h[u]; ~i; i = ne[i]) {
      int j = e[i];
      if (dist[j] > dist[u] + w[i]) {
        dist[j] = dist[u] + w[i];
        if (!st[j])
          q.push(j), st[j] = true;
      }
    }
  }
  if (dist[n] > inf / 2)
    cout << "impossible" << endl;
  else
    cout << dist[n] << endl;
}

int main() {
  memset(h, -1, sizeof h);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    add(a, b, c);
  }
  spfa();
  return 0;
}
