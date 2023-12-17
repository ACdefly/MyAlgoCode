/*
* @Author: wlun
* @Date:   2023-08-21 16:23:42
* @Last Modified by:   wlun
* @Last Modified time: 2023-08-21 16:24:32
*/

#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using std::queue;
using std::vector;

const int N = 1e5 + 10;
vector<int> vec[N];
int dist[N];
int n, m;

void bfs() {
  memset(dist, -1, sizeof dist);
  queue<int> q;
  q.push(1);
  dist[1] = 0;
  while (q.size()) {
    auto t = q.front();
    if(t == n) {std::cout << dist[n] << "\n"; return ;}
    q.pop();
    for (auto p : vec[t]) {
      if (dist[p] == -1) {
        dist[p] = dist[t] + 1;
        q.push(p);
      }
    }
  }
  std::cout << "-1\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    std::cin >> a >> b;
    vec[a].push_back(b);
  }
  bfs();
  return 0;
}
