/*
 * @Author: wlun
 * @Date:   2023-08-22 10:04:11
 * @Last Modified by:   wlun
 * @Last Modified time: 2023-08-22 10:27:17
 */

#include <cstring>
#include <iostream>
#define inf 0x3f3f3f3f
using namespace std;

const int N = 510, M = 1e4 + 10;
int w[M], e[M], ne[M], h[N], idx = 0;
int n, m, k;
int dist[N], backup[N];

void add(int a, int b, int c)
{
    w[idx] = c, e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

auto bellman_ford() -> void {
    memset(dist, 0x3f, sizeof(h));
    dist[1] = 0;
    for(int i = 0; i < k; i++)
    {
        memcpy(backup, dist, sizeof(dist));
        for(int u = 1; u <= n; u++){
            for(int j = h[u]; ~j; j = ne[j]){
                int v = e[j];
                dist[v] = min(dist[v], backup[u] + w[j]);
            }
        }
    }
    if(dist[n] > inf / 2) cout << "impossible" << endl;
    else cout << dist[n] << endl;
}

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr);
  cin >> n >> m >> k;
  memset(h, -1, sizeof(h));
  for (int i = 1; i <= m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    add(a, b, c);
  }
  bellman_ford();
  return 0;
}
