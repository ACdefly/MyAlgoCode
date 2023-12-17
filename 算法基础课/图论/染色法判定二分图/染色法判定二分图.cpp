/*
* @Author: wlun
* @Date:   2023-08-22 20:58:15
* @Last Modified by:   wlun
* @Last Modified time: 2023-08-22 22:31:23
*/

#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e5 + 10;
int e[N << 1], ne[N << 1], h[N], idx = 0;
int color[N];
int q[N];
int hh, tt;
int n, m;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool bfs(int s, int c)
{
    hh = 0, tt = -1;
    color[s] = c;
    q[++tt] = s;
    while(hh <= tt)
    {
        int u = q[hh++];
        for(int i = h[u]; ~i; i = ne[i])
        {
            int v = e[i];
            if(!color[v])
            {
                color[v] = 3 - color[u];
                q[++tt] = v;
            }
            else if(color[u] == color[v])  return false;
        }
    }
    return true;
}

int main()
{

    memset(h, -1, sizeof h);
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int a, b; cin >> a >> b;
        add(a, b), add(b, a);
    }
    bool f = true;
    for(int i = 1; i <= n; i++)
    {
        if(!color[i])
        {
            if(!bfs(i, 1)) {
                f = false;
                break;
            }
        }
    }
    cout << (f ? "Yes" : "No") << endl;
    return 0;
}
