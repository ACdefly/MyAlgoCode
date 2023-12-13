// Problem: P1160 队列安排
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1160
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>

using namespace std;

const int N = 1e5 + 10;

struct Node 
{
  int l, r;
}node[N];
bool st[N];

void insert(int i, int k, int p) {
  if(p == 0) {
    node[i].r = k;
    node[i].l = node[k].l;
    node[node[k].l].r = i;
    node[k].l = i;
  }
  else {
    node[i].r = node[k].r;
    node[i].l = k;
    node[node[k].r].l = i;
    node[k].r = i;
  }
}

void del(int i)
{
  st[i] = true;
  int l = node[i].l, r = node[i].r;
  node[r].l = l;
  node[l].r = r;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n, m;
  cin >> n;
  node[0].l = node[0].r = 0;
  insert(1, 0, 1);
  for(int i = 2; i <= n; i++) 
  {
    int k, p; cin >> k >> p;
    insert(i, k, p);
  }
  cin >> m;
  while(m--){
    int x; cin >> x;
    if(!st[x]) del(x);
  }
  for(int i = node[0].r; i; i = node[i].r)
  {
    cout << i << ' ';
  }
  return 0;
}
