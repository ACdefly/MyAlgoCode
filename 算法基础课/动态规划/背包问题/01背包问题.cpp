/*
* @Author: wlun
* @Date:   2024-01-13 22:53:04
* @Last Modified by:   wlun
* @Last Modified time: 2024-01-13 23:13:31
*/
// #include <iostream>

// const int N = 1010;

// int f[N][N], v[N], w[N];

// int main()
// {
//     int N, V;
//     std::cin >> N >> V;
//     for(int i = 1; i <= N; i++) std::cin >> v[i] >> w[i];
//     int res = 0;
//     for(int i = 1; i <= N; i++)
//     {
//         for(int j = 1; j <= V; j++) {
//             if(j - v[i] >= 0) {
//                 f[i][j] = std::max(f[i - 1][j - v[i]] + w[i], f[i - 1][j]);
//             } else f[i][j] = f[i - 1][j];
//         }
//     }
//     std::cout << f[N][V] << "\n";
//     return 0;
// }

#include <iostream>

const int N = 1010;

int f[N], v[N], w[N];

int main()
{
    int n, m;
    std::cin >> n >> m;

    for(int i = 1; i <= n; i++) std::cin >> v[i] >> w[i];

    for(int i = 1; i <= n; i++) {
        for(int j = m; j >= v[i]; j--) {
            f[j] = std::max(f[j - v[i]] + w[i], f[j]);
        }
    }
    std::cout << f[m] << "\n";
    return 0;
}
