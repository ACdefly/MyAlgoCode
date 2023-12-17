
// 稠密图
#include <cstring>
#include <iostream>
#define inf 0x3f3f3f3f
using namespace std;

const int N = 510;
int g[N][N];
int dist[N];
bool st[N];
int n, m;

void prim() {
  int res = 0;
  memset(dist, 0x3f, sizeof dist);
  dist[1] = 0;
  for (int i = 1; i <= n; i++) {
    int u = 0;
    for (int j = 1; j <= n; j++) {
      if (!st[j] && dist[j] < dist[u])
        u = j;
    }
    if (dist[u] == inf) {
      cout << "impossible\n";
      return;
    }
    st[u] = true;
    res += dist[u];
    for (int j = 1; j <= n; j++) {
      if (g[u][j] < dist[j])
        dist[j] = g[u][j];
    }
  }
  cout << res << "\n";
}

int main() {
  cin >> n >> m;
  memset(g, 0x3f, sizeof g);
  for (int i = 1; i <= m; i++) {
    int a, b, w;
    cin >> a >> b >> w;
    g[a][b] = g[b][a] = min(g[a][b], w);
  }
  prim();
  return 0;
}
