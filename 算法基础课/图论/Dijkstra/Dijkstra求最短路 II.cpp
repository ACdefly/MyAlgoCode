/*
* @Author: wlun
* @Date:   2023-08-21 22:02:33
* @Last Modified by:   wlun
* @Last Modified time: 2023-08-21 23:18:42
*/

#include <iostream>
#include <cstring>
#include <queue>
#define inf 0x3f3f3f3f
using namespace std;
using PII = pair<int, int>;

const int N = 150010;
int e[N], ne[N], h[N], w[N], idx = 0;
int dist[N];
bool st[N];
int n, m;

void add(int a, int b, int c)
{
    w[idx] = c, e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}


void dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> q;
    q.push({0, 1});
    while(!q.empty())
    {
        auto t = q.top();
        q.pop();
        if(st[t.second]) continue;
        st[t.second] = true;
        for(int i = h[t.second]; i != -1; i = ne[i])
        {
            int j = e[i];
            if(dist[j] > dist[t.second] + w[i])
            {
                dist[j] = dist[t.second] + w[i];
                q.push({dist[j], j});
            }
        }
    }
    cout << (dist[n] == inf ? -1 : dist[n]) << endl;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    memset(h, -1, sizeof h);
    cin >> n >> m;
    while(m--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        add(a, b, w);
    }
    dijkstra();

    return 0;
}
