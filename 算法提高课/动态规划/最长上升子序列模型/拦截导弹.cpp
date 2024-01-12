/*
* @Author: wlun
* @Date:   2024-01-07 16:18:41
* @Last Modified by:   wlun
* @Last Modified time: 2024-01-07 17:16:02
*/


#include <iostream>

using namespace std;

const int N = 1010;

int h[N];
int f[N], g[N];
int n = 0;

int main()
{
    while(cin >> h[n]) n++;
    int ans  = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        f[i] = g[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if(h[i] <= h[j]) f[i] = max(f[i], f[j] + 1);
            else g[i] = max(g[i], g[j] + 1);
        }
        ans = max(f[i], ans);
        cnt = max(g[i], cnt);
    }
    cout << ans << endl;
    cout << cnt << endl;
    return 0;
}
