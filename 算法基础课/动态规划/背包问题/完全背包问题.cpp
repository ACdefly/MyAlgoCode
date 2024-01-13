/*
* @Author: wlun
* @Date:   2024-01-13 23:18:03
* @Last Modified by:   wlun
* @Last Modified time: 2024-01-13 23:24:24
*/
#include <iostream>

const int N = 1010;

int f[N], v[N], w[N];

int main()
{
    int n, m;
    std::cin >> n >> m;

    for(int i = 1; i <= n; i++) std::cin >> v[i] >> w[i];

    for(int i = 1; i <= n; i++) {
        for(int j = v[i]; j <= m; j++) {
            f[j] = std::max(f[j - v[i]] + w[i], f[j]);
        }
    }
    std::cout << f[m] << "\n";
    return 0;
}
