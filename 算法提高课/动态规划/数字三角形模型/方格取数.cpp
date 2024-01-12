/*
* @Author: wlun
* @Date:   2024-01-02 13:29:04
* @Last Modified by:   wlun
* @Last Modified time: 2024-01-05 17:03:12
*/
/*
#include <bits/stdc++.h>

using namespace std;

const int N = 15;

int w[N][N];
int f[N << 1][N][N];

void solve()
{
    int n;
    cin >> n;
    int a, b, c;
    while(cin >> a >> b >> c, a || b || c) w[a][b] = c;
    for(int k = 2; k <= (n << 1); k++) {
        for(int i1 = 1; i1 <= n; i1++) {
            for(int i2 = 1; i2 <= n; i2++) {
                int j1 = k - i1, j2 = k - i2;
                if(j1 >= 1 && j1 <= n && j2 >= 1 && j2 <= n)
                {
                    int t = w[i1][j1];
                    if(i1 != i2) t += w[i2][j2];
                    int &x = f[k][i1][i2];
                    x = max(x, f[k - 1][i1 - 1][i2 - 1] + t);
                    x = max(x, f[k - 1][i1 - 1][i2] + t);
                    x = max(x, f[k - 1][i1][i2 - 1] + t);
                    x = max(x, f[k - 1][i1][i2] + t);
                }
            }
        }
    }
    cout << f[n << 1][n][n] << endl;
}

int main()
{
    int t;
    // cin >> t;
    t = 1;
    while(t--) solve();
    return 0;
}
*/

#include <bits/stdc++.h>

const int N = 10;

int w[N][N];
int dp[N][N][N][N];

inline int max(int a, int b, int c, int d)
{
    int x = a > b ? a : b;
    int y = c > d ? c : d;
    return x > y ? x : y;
}

int main()
{
    int n;
    std::cin >> n;
    int a, b, c;
    while(std::cin >> a >> b >> c && (a || b || c))
    {
        w[a][b] = c;
    }
    for(int i1 = 1; i1 <= n; i1++)
        for(int j1 = 1; j1 <= n; j1++)
            for(int i2 = 1; i2 <= n; i2++)
                for(int j2 = 1; j2 <= n; j2++)
                {
                    dp[i1][j1][i2][j2] = max(dp[i1 - 1][j1][i2 - 1][j2], dp[i1 - 1][j1][i2][j2 - 1],
                        dp[i1][j1 - 1][i2 - 1][j2], dp[i1][j1 - 1][i2][j2 - 1]) + w[i1][j1] + w[i2][j2];
                    if(i1 == i2 && j1 == j2) dp[i1][j1][i1][j1] -= w[i1][j1];
                }
    std::cout << dp[n][n][n][n] << std::endl;
    return 0;
}
