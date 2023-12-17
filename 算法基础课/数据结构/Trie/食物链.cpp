/*
* @Author: wlun
* @Date:   2023-08-19 11:14:47
* @Last Modified by:   wlun
* @Last Modified time: 2023-08-19 16:52:33
*/

#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 10;
int p[N], d[N];
int n, k;

int find(int x)
{
    if(x != p[x])
    {
        int t = find(p[x]);
        d[x] +=d[p[x]];
        p[x] = t;
    }
    return p[x];
}

void init()
{
    memset(d, 0, sizeof d);
    for(int i = 1; i <= n; i++)
    {
        p[i] = i;
    }
}

int main()
{
    cin >> n >> k;
    init();
    int D, x, y;
    int ans = 0;
    for(int i = 0; i < k; i++)
    {
        cin >> D >> x >> y;
        if(x > n || y > n){
            ans++;
            continue;
        }
        int a = find(x), b = find(y);
        if(D == 1)
        {
            if(a == b && (d[x] - d[y]) % 3) ans++;
            else if(a != b) {
                p[a] = b;
                d[a]  = d[y] - d[x];
            }
        } else {
            if(a == b && (d[x] - d[y] - 1) % 3) ans++;
            else if(a != b) {
                p[a] = b;
                d[a] = d[y] + 1 - d[x];
            }
        }
    }
    cout << ans << endl;
    return 0;
}
