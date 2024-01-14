/*
* @Author: wlun
* @Date:   2024-01-13 23:30:37
* @Last Modified by:   wlun
* @Last Modified time: 2024-01-14 22:14:25
*/

/*#include <iostream>

const int N = 110;

int v[N], w[N], s[N];
int f[N][N];

int main(int argc, char const *argv[])
{
    int n, m;
    std::cin >> n >> m;
    for(int i = 1; i <= n; i++) std::cin >> v[i] >> w[i] >> s[i];
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            for(int k = 0; k <= s[i] and k * v[i] <= j; k++) {
                f[i][j] = std::max(f[i][j], f[i - 1][j - k * v[i]] + k * w[i]);
            }
        }
    }
    std::cout << f[n][m] << "\n";
    return 0;
}*/

/*#include <iostream>

const int N = 110;

int v[N], w[N], s[N];
int f[N];

int main()
{
    int n, m;
    std::cin >> n >> m;
    for(int i = 1; i <= n; i++) std::cin >> v[i] >> w[i] >> s[i];

    for(int i = 1; i <= n; i++) {
        for(int j = m; j >= v[i]; j--) {
            for(int k = 0; k <= s[i] && k * v[i] <= j; k++)
                f[j] = std::max(f[j], f[j - k * v[i]] + k * w[i]);
        }
    }
    std::cout << f[m] << "\n";
    return 0;
}*/

// 单调队列优化
#include <iostream>
#include <cstring>

const int N = 110;

int f[N], g[N], q[N];

int main()
{
    int n, m;
    std::cin >> n >> m;
    int v, w, s;
    for(int i = 1; i <= n; i++) {
        memcpy(g, f, sizeof f);
        std::cin >> v >> w >> s;
        for(int j = 0; j < v; j++) { // 拆分成v个类
            int hh = 0, tt = -1;
            for(int k = j; k <= m; k += v) {
                // q[hh]不在窗口 [k - s * v, k - v] 出队
                if(hh <= tt && q[hh] < k - s * v) hh++;
                // 对头更新最大值 f
                if(hh <= tt) f[k] = std::max(g[k], g[q[hh]] + (k - q[hh]) / v * w);
                while(hh <= tt && g[k] >= g[q[tt]] + (k - q[hh]) / v * w) tt--;
                q[++tt] = k;
            }
        }
    }
    std::cout << f[m] << "\n";
    return 0;
}
