/*
* @Author: wlun
* @Date:   2024-01-07 21:14:46
* @Last Modified by:   wlun
* @Last Modified time: 2024-01-09 13:36:35
*/
#include <iostream>

using namespace std;

const int N = 55;

int n;
int h[N], down[N], up[N];
int ans = 0;
/*
* u -> 当前枚举到的位置
* su -> 当前上升子序列的个数
* sd -> 当前下降子序列的个数
*/
void dfs(int u, int su, int sd)
{
    if(su + sd >= ans) return;
    if(u == n + 1) {
        ans = su + sd;
        return;
    }

    // 1. 当前数在上升子序列中
    int k = 0;
    while(k < su && up[k] >= h[u]) k++;
    int t = up[k];
    up[k] =h[u];
    if(k < su) dfs(u + 1, su, sd);
    else dfs(u + 1, su + 1, sd);
    up[k] = t;

    // 2. 当前数在下降子序列中
    k = 0;
    while(k < sd && down[k] <= h[u]) k++;
     t = down[k];
    down[k] = h[u];
    if(k < sd) dfs(u + 1, su, sd);
    else dfs(u + 1, su, sd + 1);
    down[k] = t;
}

int main()
{
    while(cin >> n, n)
    {
        for(int i = 1; i <= n; i++) cin >> h[i];
        ans = n;
        dfs(1, 0, 0);
        cout << ans << endl;
    }
    return 0;
}
