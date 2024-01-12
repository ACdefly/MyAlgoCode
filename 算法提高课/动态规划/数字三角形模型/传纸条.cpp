/*
* @Author: wlun
* @Date:   2024-01-06 13:31:44
* @Last Modified by:   wlun
* @Last Modified time: 2024-01-06 14:19:47
*/
#include <iostream>

using namespace std;

const int N = 55;
int w[N][N];
int f[N << 1][N][N];

int Max(int &a, int &b, int &c, int &d) {
    int x = a > b ? a : b;
    int y = c > d ? c : d;
    return x > y ? x : y;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) cin >> w[i][j];
    }
    for(int k = 2; k <= n + m; k++)
        for(int i1 = 1; i1 < k && i1 <= n; i1++)
            for(int i2 = 1; i2 < k && i2 <= n; i2++)
            {
                int j1 = k - i1, j2 = k - i2;
                // if(j1 < 1 || j1 > m || j2 < 1 || j2 > m) continue;
                int v = w[i1][j1];
                if(i1 != i2) v += w[i2][j2];
                f[k][i1][i2] = Max(f[k - 1][i1 - 1][i2], f[k - 1][i1 - 1][i2 - 1], f[k - 1][i1][i2 - 1], f[k - 1][i1][i2]);
                f[k][i1][i2] += v;
            }
    cout << f[n + m][n][n] << endl;
    return 0;
}
