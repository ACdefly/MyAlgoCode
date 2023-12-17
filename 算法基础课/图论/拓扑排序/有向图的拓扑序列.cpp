/*
* @Author: wlun
* @Date:   2023-08-21 20:17:25
* @Last Modified by:   wlun
* @Last Modified time: 2023-08-21 21:56:20
*/

#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e5 + 10;

int e[N], ne[N], h[N], idx = 0;
int d[N];
int que[N];

int n, m;
int hh = 0, tt = -1;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void top_sort()
{

    for(int i = 1; i <= n; i++) {
        if(d[i] == 0) que[++tt] = i;
    }
    while(hh <= tt)
    {
        int u = que[hh++];
        for(int i = h[u]; ~i; i = ne[i])
        {
            int v = e[i];
            d[v]--;
            if(!d[v]) que[++tt] = v;
        }
    }
    if(tt == n - 1) {
        for(int i = 0; i < n; i++) cout << que[i] << ' ';
        return;
    }
    cout << -1 << endl;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    memset(h, -1, sizeof h);
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        add(a, b);
        d[b]++;
    }
    top_sort();
    return 0;
}
