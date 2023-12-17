/*
* @Author: wlun
* @Date:   2023-08-21 22:02:33
* @Last Modified by:   wlun
* @Last Modified time: 2023-08-21 22:32:56
*/

#include <iostream>
#include <cstring>
#define inf 0x3f3f3f3f

using namespace std;

const int N = 510;
int g[N][N];
int dist[N];
bool st[N];
int n, m;

void dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    for(int i = 0; i < n; i++)
    {
        int u = 0;
        for(int j = 1; j <= n; j++)
        {
            if(!st[j] && dist[j] < dist[u]) u = j;
        }
        st[u] = true;
        for(int j = 1; j <= n; j++)
        {
            dist[j] = min(dist[j], dist[u] + g[u][j]);
        }
    }
    cout << (dist[n] == inf ? -1 : dist[n]) << endl;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    memset(g, 0x3f, sizeof g);

    cin >> n >> m;
    while(m--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        g[a][b] = min(g[a][b], w);
    }
    dijkstra();
    return 0;
}
