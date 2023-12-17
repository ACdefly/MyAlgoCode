/*
* @Author: wlun
* @Date:   2023-08-22 13:14:46
* @Last Modified by:   wlun
* @Last Modified time: 2023-08-22 13:40:54
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;

const int N = 100010;
int w[N], e[N], ne[N], h[N], idx = 0;
int dist[N], cnt[N];
int n, m;

void add(int a, int b, int c)
{
    w[idx] = c, e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool spfa()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    bool f;
    for(int i = 1; i <= n; i++){
        f = false;
        for(int u = 1; u <= n; u++){
            if(dist[u] > inf /2) continue;
            for(int j = h[u]; ~j; j = ne[j]){
                int t = e[j];
                if(dist[t] > dist[u] + w[j]){
                    dist[t] = dist[u] + w[j];
                    f = true;
                }
            }
        }
        if(!f) break;
    }
    return f;
}

int main()
{
    memset(h, -1, sizeof h);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }
    if(spfa()) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}
