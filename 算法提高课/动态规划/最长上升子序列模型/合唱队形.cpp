/*
* @Author: wlun
* @Date:   2024-01-06 22:50:10
* @Last Modified by:   wlun
* @Last Modified time: 2024-01-06 22:52:03
*/
#include <iostream>

using namespace std;

const int N = 110;
int h[N];
int f[2][N];

void solve()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> h[i];
    for(int i = 1; i <= n; i++) {
        f[0][i] = 1;
        for(int j = 1; j < i; j++) {
            if(h[j] < h[i]) f[0][i] = max(f[0][j] + 1, f[0][i]);
        }
    }
    for(int i = n; i >= 1; i--) {
        f[1][i] = 1;
        for(int j = n; j > i; j--) {
            if(h[j] < h[i]) f[1][i] = max(f[1][i], f[1][j] + 1);
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) ans = max(ans, f[0][i] + f[1][i] - 1);
    cout << n - ans << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}
