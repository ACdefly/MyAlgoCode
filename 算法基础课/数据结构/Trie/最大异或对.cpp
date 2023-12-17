/*
* @Author: wlun
* @Date:   2023-08-19 00:46:12
* @Last Modified by:   wlun
* @Last Modified time: 2023-08-19 00:55:07
*/

#include <bits/stdc++.h>

constexpr int N = 1e5 + 10, M = 31 * N;
int a[N];
int tr[M][2], idx = 0;

void insert(int x)
{
    int p = 0;
    for(int i = 30; i >=0; i--)
    {
        int u = x >> i & 1;
        if(!tr[p][u]) tr[p][u] = ++idx;
        p = tr[p][u];
    }
}

int query(int x)
{
    int p = 0;
    int res = 0;
    for(int i = 30; i >= 0; i--)
    {
        int u = x >> i & 1;
        if(tr[p][!u])
        {
            res = res * 2 + !u;
            p = tr[p][!u];
        } else {
            res = res * 2 + u;
            p = tr[p][u];
        }
    }
    return res;
}

int main()
{
    std::cin.tie(nullptr) -> sync_with_stdio(false);
    int n;
    std::cin >> n;
    for(int i = 0; i < n; i++) std::cin >> a[i];

    int res = 0;
    for(int i = 0; i < n; i++)
    {
        insert(a[i]);
        int t = query(a[i]);
        res = std::max(res, t ^ a[i]);
    }
    std::cout << res << "\n";
    return 0;
}
